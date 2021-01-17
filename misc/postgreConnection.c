/* God willing this will connect to my local postgre server */
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>



void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

int main (int argc, char **argv){
    const char *conninfo;
    PGconn *conn;
    PGresult *res;
    PGnotify *notify;
    int nFields;
    int i, j;

    /*
     * If the user supplies a paramter on the command line, user it as
     * the conninfo string; otherwise default to setting dbname=postgres
     * and using environment variables or defaults for all other connection paramters
     */

    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "dbname = postgres";

    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /* Check that the connection is successful */
    if (PQstatus(conn) != CONNECTION_OK) 
    {
        printf("PQstatus(conn) not equal to CONNECTION_OK");
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    } 

    /* Our test case here involves using a cursor, for which we must be inside
     * a transaction block. We could do teh whole thing with a single
     * PQexec() of "select * from pg_database", but that's too trivial to make
     * a good example
     */

    /* Start a transaction block */
    res = PQexec(conn, "BEGIN");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        do_exit(conn);
    }

    /*
     * Should PQclear PGresult whenever it is no longer needed to avoid memory 
     * leaks
     */
    PQclear(res);

    /*
     * Fetch rows from pg_database, the system catalog of databases
     */
    res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from pg_database");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
        PQclear(res);
        do_exit(conn);
    }
    PQclear(res);

    res = PQexec(conn, "FETCH ALL in myportal");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        PQclear(res);
        do_exit(conn);
    }

    /* First print out the attribute names */
    nFields = PQnfields(res);
    for (i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");

    /* next print out the rows */
    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    }

    PQclear(res);

    /* close the portal , we don't bother to check for errors here */
    res = PQexec(conn, "CLOSE myportal");
    PQclear(res);

    /* end the transaction */
    res = PQexec(conn, "END");
    PQclear(res);

    /* close the connection to the database and cleanup */
    PQfinish(conn);
    return 0;
}


/* sizeof.c--Program to tell the size of the C variable types */
/*                                      in bytes.             */

#include <stdio.h>

int main(void)
{
    printf("\nA char        is %d bytes", sizeof( char ));
    printf("\nAn int        is %d bytes", sizeof( int ));
    printf("\nAn short      is %d bytes", sizeof( short ));
    printf("\nAn long       is %d bytes", sizeof( long ));
    printf("\nAn long long  is %d bytes", sizeof( long long ));
    printf("\nAn unsigned char    is %d bytes", sizeof( unsigned char ));
    printf("\nAn unsigned int        is %d bytes", sizeof( unsigned int ));
    printf("\nAn unsigned short        is %d bytes", sizeof( unsigned short ));
    printf("\nAn unsigned long        is %d bytes", sizeof( unsigned long ));
    printf("\nAn unsigned long long        is %d bytes", sizeof( unsigned long long ));
    printf("\nAn float        is %d bytes", sizeof( float ));
    printf("\nAn double        is %d bytes", sizeof( double ));
    printf("\nAn long double        is %d bytes", sizeof( long double ));

    return 0;
}

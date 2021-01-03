/* simplestruct.c - Demonstrates the use of a simple structures */

#include <stdio.h>

int length, width;
long area;

struct coord {
    int x;
    int y;
} myPoint;

int main(void)
{
    /* set values into the coordinates */
    myPoint.x = 12;
    myPoint.y = 14;

    printf("\nThe coordinates are: (%d, %d).\n",
            myPoint.x, myPoint.y);

    return 0;
}

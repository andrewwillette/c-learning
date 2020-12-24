#include <stdio.h>

int x, y;

int main(void){
    // This is new to me... looks like there are no brackets in for loops
    // Looks like I can include oneliner function calls in a comma after for loop
    // What the...
    for (x=0; x<10; x++, printf("\n"))
        for(y=0; y<10; y++)
            printf("X");

    return 0;
}

#include <stdio.h> 

float radius, area;

int main(void){
    printf("Enter radius : ");
    scanf ("%f", &radius);
    area =  (3.14159 * radius * radius);
    printf("\n\nArea = %f\n", area);
}

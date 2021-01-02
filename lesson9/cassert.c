#include <stdio.h>
#include <assert.h>

short arr[6], *p_arr;
float express[6], *p_express;


int main(void)
{
    printf("entering main\n");

    p_arr = &arr[0];
    p_express = &express[0];

    printf("Start address of short array is: %p\n", p_arr);
    p_arr = &arr[1];
    printf("address 2 of short array is: %p\n", p_arr);
    p_arr = &arr[2];
    printf("address 3 of short array is: %p\n", p_arr);

    printf("Start address of express array is: %p\n", p_express);
    p_express = &express[1];
    printf("address 2 of express array is: %p\n", p_express);
    p_express = &express[2];
    printf("address 3 of express array is: %p\n", p_express);

    p_express = &express[0];
    assert(p_express == express);
    return 0;
}

/* Calculates how much money my brother owes me for monthly payments */

#include <stdio.h>

float rent, electricity, totalPayment, amountOwed;

int main (void) {
    printf("What was rent payment this month? : ");
    scanf("%f", &rent);
    printf("What was electricity payment this month? : ");
    scanf("%f", &electricity);

    totalPayment = rent + electricity;

    printf("\nTotal amount paid is %.2f\n", totalPayment);

    amountOwed = totalPayment / 2;

    printf("\nRoommate owes you %.2f\n", amountOwed);
}
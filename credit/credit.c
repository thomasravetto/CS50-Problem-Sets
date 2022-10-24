#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit;
    //prompting user for card number, asking again if the card number is negative
    do
    {
        credit = get_long("Enter credit card numer: ");
    }
    while (credit < 0);

//taking every other number starting from the second last digit
    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((credit % 100) / 10) * 2;
    card2 = ((credit % 10000) / 1000) * 2;
    card3 = ((credit % 1000000) / 100000) * 2;
    card4 = ((credit % 100000000) / 10000000) * 2;
    card5 = ((credit % 10000000000) / 1000000000) * 2;
    card6 = ((credit % 1000000000000) / 100000000000) * 2;
    card7 = ((credit % 100000000000000) / 10000000000000) * 2;
    card8 = ((credit % 10000000000000000) / 1000000000000000) * 2;

//summing every two digits number together
    card1 = (card1 % 100 / 10) + (card1 % 10);
    card2 = (card2 % 100 / 10) + (card2 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card4 = (card4 % 100 / 10) + (card4 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card6 = (card6 % 100 / 10) + (card6 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card8 = (card8 % 100 / 10) + (card8 % 10);

//summing numbers together
    int sum1;
    sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

//taking the digits that were not multiplied by 2
    int card9, card10, card11, card12, card13, card14, card15, card16;

    card9 = (credit % 10);
    card10 = ((credit % 1000) / 100);
    card11 = ((credit % 100000) / 10000);
    card12 = ((credit % 10000000) / 1000000);
    card13 = ((credit % 1000000000) / 100000000);
    card14 = ((credit % 100000000000) / 10000000000);
    card15 = ((credit % 10000000000000) / 1000000000000);
    card16 = ((credit % 1000000000000000) / 100000000000000);

//summing numbers together
    int sum2;
    sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

//summing the two sums
    int valid;
    valid = sum1 + sum2;

    long mc = credit;
    long visa = credit;
    long amex = credit;
    int digits = 0;

//finding if the card is invalid
    if (valid % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
//finding card length
    while (credit > 0)
    {
        credit = credit / 10;
        digits++;
    }

//finding if the card is a VISA
    while (visa >= 10)
    {
        visa = visa / 10;
    }
    if (visa == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
        return 0;
    }

//finding if the card is a mastercard
    while (mc >= 100000000000000)
    {
        mc /= 100000000000000;
    }
    if (digits == 16 && (mc > 50 && mc < 56))
    {
        printf("MASTERCARD\n");
        return 0;
    }

//finding if the card is an amex
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (digits == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    printf("INVALID\n");
}
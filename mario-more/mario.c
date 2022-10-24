#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //assigning integers
    int n, r, c, s;
    do
        //prompting user for imput between 1 and 8
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //printing rows
    for (r = 0; r < n; r++)
    {
        //printing spaces before first pyramid
        for (s = 0; s < n - r - 1; s++)
        {
            printf(" ");
        }
        //printing # for first pyramid
        for (c = 0; c <= r; c++)
        {
            printf("H");
        }
        //printing spaces between pyramids
        printf("  ");
        for (c = 0; c <= r; c++)
            //printing # for second pyramid
        {
            printf("H");
        }
        //beginning a new line
        printf("\n");
    }




}
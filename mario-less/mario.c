#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //n = height of the pyramid, c = columns, l = lines
    int n;
    do
    {
        //take user imput to decide the pyramid's height
        n = get_int("Height; ");
    }
    //asking the user again if the imput is not between 1 and 8
    while (n < 1 || n > 8);

// printing each line
    for (int l = 0; l < n; l++)
    {
        // printing each column
        for (int d = 0; d < n - l -1; d++)
        {
            printf(" ");
        }
        for (int j = 0; j < l; j++)
        {
            printf("#");
        }
         printf("  ");
        for(int c = 0; c <= r; c++)
        {
            printf("#");
        }

        printf("\n");

        printf("\n");
    }
}
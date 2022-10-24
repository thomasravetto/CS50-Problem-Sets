#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int tot_value = 0;
char number[1000];

int main(void)
{
    printf("Please input a number to convert, valid digits: I, V, X, C, D, M\n");
    scanf("%s", number);

    for (int i = 0; i < strlen(number); i++)
    {
        if (islower(number[i]))
        {
            printf("Please input only uppercase letters\n");
            return 1;
        }

        if (number[i] < number[i + 2])
        {
            printf("Invalid roman number\n");
            return 2;
        }
    }

    //checking every symbol and assigning value
    for (int i = 0; i < strlen(number); i++)
    {
        if (number[i] == 'I')
        {
            if (number[i + 1] == 'V' || number[i + 1] == 'X')
            {
                continue;
            }
            else
            {
                tot_value += 1;
            }
        }

        if (number[i] == 'V')
        {
            if (number[i - 1] == 'I')
            {
                tot_value += 4;
            }
            else
            {
                tot_value += 5;
            }
        }

        if (number[i] == 'X')
        {
            if (number[i + 1] == 'L' || number[i + 1] == 'C')
            {
                continue;
            }
            else if (number[i - 1] == 'I')
            {
                tot_value += 9;
            }
            else
            {
                tot_value += 10;
            }
        }

        if (number[i] == 'L')
        {
            if (number[i - 1] == 'X')
            {
                tot_value += 40;
            }
            else
            {
                tot_value += 50;
            }
        }

        if (number[i] == 'C')
        {
            if (number[i + 1] == 'D' || number[i + 1] == 'M')
            {
                continue;
            }
            else if (number[i - 1] == 'X')
            {
                tot_value += 90;
            }
            else
            {
                tot_value += 100;
            }
        }

        if (number[i] == 'D')
        {
            if (number[i - 1] == 'C')
            {
                tot_value += 500;
            }
            else
            {
                tot_value += 400;
            }
        }

        if (number[i] == 'M')
        {
            if (number[i - 1] == 'C')
            {
                tot_value += 900;
            }
            else
            {
                tot_value += 1000;
            }
        }
    }
    printf("The number in integer is: %i\n", tot_value);
    return 0;
}
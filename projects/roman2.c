#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int tot_value = 0;
char number[1000];
char *s;

int romanToInt(void)
{
    printf("Please input a number to convert: (I, V, X, C, D, M) \n");
    printf("%s", s);
    scanf("%s", s);

    if (islower(s))
    {
        printf("Please input only uppercase letters\n");
        return 1;
    }



    //checking every symbol and assigning value
    for (int i = 0; i < strlen(s); i++)
    {

        if (number[i] < number[i + 2])
        {
            printf("Invalid roman number\n");
            return 2;
        }

        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                continue;
            }
            else
            {
                tot_value += 1;
            }
        }

        if (s[i] == 'V')
        {
            if (s[i - 1] == 'I')
            {
                tot_value += 4;
            }
            else
            {
                tot_value += 5;
            }
        }

        if (s[i] == 'X')
        {
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
            {
                continue;
            }
            else if (s[i - 1] == 'I')
            {
                tot_value += 9;
            }
            else
            {
                tot_value += 10;
            }
        }

        if (s[i] == 'L')
        {
            if (s[i - 1] == 'X')
            {
                tot_value += 40;
            }
            else
            {
                tot_value += 50;
            }
        }

        if (s[i] == 'C')
        {
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
            {
                continue;
            }
            else if (s[i - 1] == 'X')
            {
                tot_value += 90;
            }
            else
            {
                tot_value += 100;
            }
        }

        if (s[i] == 'D')
        {
            if (s[i - 1] == 'C')
            {
                tot_value += 500;
            }
            else
            {
                tot_value += 400;
            }
        }

        if (s[i] == 'M')
        {
            if (s[i - 1] == 'C')
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
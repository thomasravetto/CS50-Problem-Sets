#include <stdio.h>
#include <string.h>
#include <ctype.h>

int roman(char c);

int main(void)
{
    //prompting the user for the roman number
    char romannum[1000];
    printf("Please input a roman number, valid digits: I, V, X, C, D, M\n");
    scanf("%s", romannum);

    //making sure the number is valid
    for (int i = 0; i < strlen(romannum); i++)
    {
        //if the number is lowercase the program will prompt the user again fo an uppercase number
        if (islower(romannum[i]))
        {
            printf("Please input only uppercase letters\n");
            return 1;
        }

        //if the roman number is invalid, the program will prompt the user again for a valid number
        if (roman(romannum[i]) < roman(romannum[i + 2]))
        {
            printf("Invalid roman number, please input a valid roman number\n");
            return 2;
        }
    }

    //calculating the final integer
    int tot_num = roman(romannum[0]);
    for (int i = 1; i < strlen(romannum); i++)
    {
        int num = roman(romannum[i]);
        int prev_num = roman(romannum[i - 1]);

        //if the previous number is smaller than the current the program will subtract
        if (prev_num < num)
        {
            tot_num = tot_num - prev_num + (num - prev_num);
        }
        else
        {
            tot_num += num;
        }
    }
    //printing the final number
    printf("%i\n", tot_num);
}

//assigning value to each symbol
int roman(char c)
{
    switch (c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
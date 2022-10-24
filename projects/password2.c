#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main(char * password)
{
    int lower, length, upper, digit, special;
    lower = upper = length = digit = special = 0;
    char *spechar = "!@#$%^&*()-+";

    for (int i = 0; password[i] != '\0'; i++)
    {
        length++;
        if(islower(password[i]))
        {
            lower++;
        }
        else if(isupper(password[i]))
        {
            upper++;
        }
        else if(isdigit(password[i]))
        {
            digit++;
        }
        for (int j = 0; spechar[j] != '\0'; j++)
        {
            if (password[i] == spechar[j])
            {
                special++;
            }
        }
    }
    if (length >= 8 && lower > 0 && upper > 0 && digit > 0 && special > 0)
    {
        return 0;
    }
    return 1;
}
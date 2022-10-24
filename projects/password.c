#include <stdio.h>
#include <string.h>
#include <ctype.h>

int islong(char*);
int lowercase(char*);
int uppercase(char*);
int digit(char*);
int special(char*);
int same(char*);

int main(void)
{
    char pass[1000];
    //prompting the user for the password to check
    printf("Input the password you want to check\n");
    scanf("%s", pass);

    //checking if the password meets all requirements
    if ((islong(pass) == 0) && (lowercase(pass) == 0) && (uppercase(pass) == 0) && (digit(pass) == 0) && (special(pass) == 0) && !(same(pass) == 0))
    {
        printf("True\n");
        return 0;
    }
    else
    {
        printf("False\n");
        return 1;
    }
}

//creating a function that returns true if the password is longer than 8 characters
int islong(char* password)
{
    if (strlen(password) >= 8)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//creating a function that returns true if the password contains at least one lowercase letter
int lowercase(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    return 1;
}

//creating a function that returns true if the password contains at least one uppercase letter
int uppercase(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    return 1;
}

//creating a function that returns true if the password contains at least one digit
int digit(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    return 1;
}

//creating a function that returns true if the password contains at least one special character "!@#$%^&*()-+"
int special(char *password)
{
    char *special = "!@#$%^&*()-+";
    for (int i = 0; i < strlen(password); i++)
    {
        for (int j = 0; j < strlen(special); j++)
        {
            if (password[i] == special[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int same(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == password[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
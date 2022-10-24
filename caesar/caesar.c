#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Making sure the command line argument is correct
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!isdigit(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Assigning the command line argument value to the key
    int key = atoi(argv[1]);

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be numeric\n");
            return 1;
        }
    }

    while (key > 26)
    {
        key -= 26;
    }

    // Getting the plaintext from the user
    string plain = get_string("Plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plain); i++)
    {

        // If the char is uppercase, the function will change the char but it will remain uppercase
        if (isupper(plain[i]))
        {
            printf("%c", toupper(((plain[i] - 'A') + key) % 26 + 'A'));
        }

        // If the char is lowercase the function will change the char
        else if (islower(plain[i]))
        {
            printf("%c", tolower(((plain[i] - 'a') + key) % 26 + 'a'));
        }

        // If the char is a number, it will remain untouched
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
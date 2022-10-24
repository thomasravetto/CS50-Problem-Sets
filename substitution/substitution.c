#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    //if the user writes more than a key, the program will stop
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    //making sure that the key that the user imputs is 26 characters long

    int lenght = strlen(argv[1]);
    if (lenght < 26 || lenght > 26)
    {
        printf("The key must be 26 characters long\n");
        return 1;
    }
    //making sure that there are no numbers in the key
    for (int i = 0; i < lenght; i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("The key must contain only letters\n");
            return 1;
        }
        //making sure that there are not repeated characters in the key
        for (int j = i + 1; j < lenght; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("The key must not contain two repeated characters\n");
                return 1;
            }
        }
    }
    //prompting the user for the plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //turning the key uppercase
    for (int k = 0; k < lenght; k++)
    {
        if (islower(key[k]))
        {
            key[k] = key[k] - 32;
        }
    }
    //substitute each letter with the one in the key
    for (int p = 0; p < strlen(plaintext); p++)
    {
        //substituting the uppercase characters
        if (isupper(plaintext[p]))
        {
            int letter = plaintext[p] - 65;
            printf("%c", key[letter]);
        }
        //substituting the lowercase characters
        else if (islower(plaintext[p]))
        {
            int letter = plaintext[p] - 97;
            printf("%c", key[letter] + 32);
        }
        //printing out the punctuation as it was before
        else
        {
            printf("%c", plaintext[p]);
        }
    }
    printf("\n");

}
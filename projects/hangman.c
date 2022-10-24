#include <stdio.h>
#include <cs50.h>
#include <string.h>

void print_hangman(int errors);
bool is_winner();

int main(void)
{
    int arm = 92;
    string word;
    char letter;
    int word_err;
    int errors = 0;
    int win = 0;

    word = get_string("Word: ");
    int word_lenght = strlen(word);
    print_hangman(errors);
    for(int i = 0; i < strlen(word); i++)
    {
        printf("_");
    }
    printf("\n");
    // creating a for loop to determine if the user letter is in the word
    while (errors < 6)
    {
        word_err = 0;
        do
        {
            letter = get_char("Letter: ");
        }
        while (strlen(&letter) < 1);
        for (int i = 0; i < strlen(word); i++)
        {
            if (letter != word[i])
            {
                word_err++;
            }
        }
        if ((word_lenght - word_err) == 0)
        {
            errors++;
        }
        else
        {
            win++;
        }
        print_hangman(errors);

        typedef struct
        {
            string letters;
            string dash;
        }
        hang;
        hang letters[strlen(word)];
        //creating a loop that assign dashes and letters
        for (int i = 0; i < strlen(word); i++)
        {
            letters[i].dash = "_";
            letters[i].letters = &word[i];
        }

        //creating a loop that prints dashes or letters based on user letter choice
            for (int i = 0; i < strlen(word); i++)
            {
                if (letter != word[i])
                {
                    printf("%.1s", letters[i].dash);
                }
                else if (letter == word[i])
                {
                    printf("%.1s", letters[i].letters);
                }
            }
            printf("\n");


            if (errors == 6)
            {
                printf("YOU LOSE!\n");
                return 0;
            }
            else if (win == strlen(word))
            {
                printf("YOU WON!\n");
                return 0;
            }
        }
}


void print_hangman(int errors)
{
    int arm = 92;
    if (errors == 0)
    {
        printf("   ____ \n  |    |\n  |\n  |\n  |\n__|__\n \n");
    }
    if (errors == 1)
    {
        printf("   ____ \n  |    |\n  |    O\n  |\n  |\n__|__\n \n");
    }
    if (errors == 2)
    {
        printf("   ____ \n  |    |\n  |    O\n  |    |\n  |\n__|__\n \n");
    }
    if (errors == 3)
    {
        printf("   ____ \n  |    |\n  |    O\n  |   /|\n  |\n__|__\n \n");
    }
    if (errors == 4)
    {
        printf("   ____ \n  |    |\n  |    O\n  |   /|%c \n  |\n__|__\n \n", arm);
    }
    if (errors == 5)
    {
        printf("   ____ \n  |    |\n  |    O\n  |   /|%c \n  |   /\n__|__\n \n", arm);
    }
    if (errors == 6)
    {
        printf("   ____ \n  |    |\n  |    O\n  |   /|%c \n  |   / %c\n__|__\n \n", arm, arm);
    }
}

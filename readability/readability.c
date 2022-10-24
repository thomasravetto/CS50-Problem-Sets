#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    //now the program will calculate the average number of letters, words and sentences in the text
    float l = (letters / words * 100);
    float s = (sentences / words * 100);

    //now the program will execute the Coleman-Liau formula to get the difficulty grade
    float grade = round(0.0588 * l - 0.296 * s - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}

//creating the function that counts letters
int count_letters(string text)
{
    int num_letters = 0;
    int lenght = strlen(text);
    for (int l = 0; l < lenght; l++)
    {
        //if there are lower or uppercase letters the function will increase num_letters by 1
        if (isupper(text[l]) || islower(text[l]))
        {
            num_letters++;
        }
    }
    return num_letters;
}


//creating the function that counts how many words there are in the text
int count_words(string text)
{
    int lenght = strlen(text);
    int num_words = 0;
    for (int l = 0; l < lenght; l++)
    {
        //if there is a blank space the function will increase num_words by 1
        if (text[l] == ' ')
        {
            num_words++;
        }
    }
    //the function will add 1 to the total number of blank spaces to get the total number of phrases
    num_words = num_words + 1;
    return num_words;
}


//creating the function that counts the sentences
int count_sentences(string text)
{
    int lenght = strlen(text);
    int num_sentences = 0;
    for (int l = 0; l < lenght; l++)
    {
        //if there is a ( . or ! or ? ) the function will increase num_sentences by 1
        if (text[l] == '.')
        {
            num_sentences++;
        }
        else if (text[l] == '!')
        {
            num_sentences++;
        }
        else if (text[l] == '?')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}
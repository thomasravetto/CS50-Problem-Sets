[#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//coding compute_score
int compute_score(string word)
{
    //using strlen to find the lenght of the words
    int lenght = strlen(word);
    int score = 0;

    for (int l = 0; l < lenght; l++)
    {
        int n = word[l];
        //figuring out if the letter is upper or lower and assigning points to int score
        if islower(word[l])
        {
            score = (score + (POINTS[n - 97]));
        }
        else if isupper(word[l])
        {
            score = (score + (POINTS[n - 65]));
        }
    }
    return score;
}

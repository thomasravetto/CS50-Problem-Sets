// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (LENGTH * 'z');

// Hash table
node *table[N];

int total_words;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Obtain hash index
    int index = hash(word);

    // Access linked list at hash address
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");  //uso fopen per aprire il documento e lo "salvo" in un FILE file
    if (file == NULL)
    {
        return false;
    }

    // Read one word at a time from file and (malloc)ing space for word
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }

        strcpy(new->word, word);
        new->next = NULL;

        // Hash word to obtain hash value
        int index = hash(word);

        // Insert word at hash location
        if (table[index] == NULL)
        {
            table[index] = new;
        }
        else
        {
            new->next = table[index];
            table[index] = new;
        }
        total_words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *temp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}

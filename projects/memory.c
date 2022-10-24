#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *original, *copy;
    char buffer[10];
    char *textcopy;

    //if file is not written, an error will occur with instructions
    if (argc != 2)
    {
        printf("Usage: ./memory FILE\n");
        return 1;
    }
    original = fopen(argv[1], "r");
    //if file can not be opened an error will occur
    if (original == NULL)
    {
        printf("File can not be opened\n");
        return 2;
    }
    copy = fopen(textcopy, "w");

    while(fread(buffer, sizeof(char), 1, original))
    {
        fwrite(buffer, sizeof(char), 1, copy);
    }
    fclose(original);
    fclose(open);
}
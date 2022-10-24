#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for name
    string name = get_string("What's your name?\n");
    //giving back hello, name
    printf("Hello,%s\n", name);
}
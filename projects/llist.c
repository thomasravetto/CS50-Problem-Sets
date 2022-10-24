#include <stdio.h>
#include <stdlib.h>

typedef struct node  //creo uno struct chiamato node, che contiene il valore e un pointer ad un altro node
{
    int value;
    struct node *next;
}
node;

int number = 25;

node *create_node(int value)  //in questa funzione andrò a creare un node
{
    node *result = malloc(sizeof(node)); //vado ad allocare dinamicamente un node result dalle dimensioni di un node
    result->value = value; //imposto il valore di result a int value
    result->next = NULL; //imposto il valore di next a NULL in modo che il pointer non punti a niente
    return result; //ritorno come risultato il node result
}

int check_list(int value, node *head)
{
    node *cursor = head;
    while(cursor != NULL)
    {
        if (cursor->value == value)
        {
            return value;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return 0;
}

void print_list(node *head)
{
    node *tmp = head;
    while(tmp != NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(void)
{
    node *head = NULL;  //creo un node head, che sarà l'inizio della mia llist
    node *tmp; //creo un node tmp che sarà usato come temporaneo all'interno di un for loop

    for (int i = number; i > 0; i--) //essendo che i nuovi elementi vengono inseriti all'inizio della lista, per contare da 0 in su faccio un loop che parte da number e arriva a 0
    {
        tmp = create_node(i); //usando create_node, assegno a tmp il valore di return, quindi tmp->value = i, tmp->next = NULL
        tmp->next = head; //assegno il valore del pointer next a head in modo che tmp si collochi davanti alla lista
        head = tmp; //
    }
    print_list(head);
    int value;
    printf("What number would you like me to find?\n");
    scanf("%i", &value);
    if (check_list(value, head))
    {
        printf("I found number %i\n", value);
    }
    else
    {
        printf("Sorry, I didn't find number\n");
    }
    return 0;
}
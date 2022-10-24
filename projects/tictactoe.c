#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int grid[3][3];
char value[3][3];

typedef struct
{
    string name; 
    char sign;
}
player;

player players[2];

void print_grid();
void reset_board();
int player1_move();
int player2_move();
int iswinner();
bool blankspaces();
bool free_move(int move);

int main(void)
{
    //prompting player1 for the name and assigning sign O
    players[0].name = get_string("Hi player1! What's your name? \n");
    players[0].sign = 'O';
    printf("Hello %s, you will play as 'O'\n", players[0].name);

    //prompting player2 for the name and assigning sign X
    players[1].name = get_string("Hi player2! What's your name? \n");
    players[1].sign = 'X';
    printf("Hello %s, you will play as 'X'\n", players[1].name);
    printf("\n");

    reset_board();
    print_grid();

    while (iswinner() || blankspaces())
    {
        player1_move();
        print_grid();
        if (iswinner() == 0)
        {
            printf("Congratulations %s, you won!\n", players[0].name);
            return 0;
        }
        else if (iswinner() == 1)
        {
            printf("Congratulations %s, you won!\n", players[1].name);
            return 0;
        }
        else if (blankspaces())
        {
            printf("It's a tie!\n");
            return 0;
        }
        player2_move();
        print_grid();
        if (iswinner() == 0)
        {
            printf("Congratulations %s, you won!\n", players[0].name);
            return 0;
        }
        else if (iswinner() == 1)
        {
            printf("Congratulations %s, you won!\n", players[1].name);
            return 0;
        }
        else if (blankspaces())
        {
            printf("It's a tie!\n");
            return 0;
        }
    }

}

void reset_board()
{
    int position = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = position;
            position++;

        }
    }
}

void print_grid()
{
    int i;
    int j;
    int a;
    int b;
    for (i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if (grid[i][j] == 'O' || grid[i][j] == 'X')
            {
                printf(" %c |", grid[i][j]);
            }
            else
            {
                printf(" %i |", grid[i][j]);
            }
        }
        if (grid[i][j] == 'O' || grid[i][j] == 'X')
        {
            printf(" %c \n", grid[i][j]);
                    }
        else
        {
            printf(" %i \n", grid[i][j]);
        }
        printf("---|---|---\n");
    }


    for (a = 2; a < 3; a++)
    {
        for(b = 0; b < 2; b++)
        {
            if (grid[a][b] == 'O' || grid[a][b] == 'X')
            {
                printf(" %c |", grid[a][b]);
            }
            else
            {
                printf(" %i |", grid[a][b]);
            }
        }
        if (grid[i][j] == 'O' || grid[a][b] == 'X')
        {
            printf(" %c\n", grid[a][b]);
        }
        else
        {
            printf(" %i \n", grid[a][b]);
        }
    }
}


int player1_move()
{
    int move1;
    int num = 1;
    int i = 0;
    int j = 0;
    do
    {
        move1 = get_int ("%s, it's your turn, please choose a square between number 1 and 9: ", players[0].name);
    }
    while((move1 > 9 || move1 < 1 || !free_move(move1)));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (move1 == num)
            {
                grid[i][j] = 'O';
                return 1;
            }
            else
            {
                num++;
            }
        }
        if (move1 == num)
        {
            grid[i][j] = 'O';
            return 1;
        }
    }
    return move1;
}



int player2_move()
{
    int move2;
    int num = 1;
    int a = 0;
    int b = 0;
    do
    {
        move2 = get_int ("%s, it's your turn, please choose a square between number 1 and 9: ", players[1].name);
    }
    while((move2 > 9 || move2 < 1 || !free_move(move2)));
    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
        if (move2 == num)
            {
                grid[a][b] = 'X';
                break;
            }
            else
            {
                num++;
            }
        }
        if (move2 == num)
        {
            grid[a][b] = 'X';
            break;
        }
    }
    return move2;
}




int iswinner()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //for each row
            if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
            {
                if (grid[i][0] == 'O')
                {
                    return 0;
                    break;
                }
                else if (grid[i][0] == 'X')
                {
                    return 1;
                    break;
                }
            }
        }
        //for each column
        for (int j = 0; j < 3; j++)
        {
            //for each row
            if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            {
                if (grid[0][i] == 'O')
                {
                    return 0;
                    break;
                }
                else if (grid[0][i] == 'X')
                {
                    return 1;
                    break;
                }
            }
        }
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        {
            if (grid[0][0] == 'O')
            {
                return 0;
                break;
            }
            else if (grid[0][0] == 'X')
            {
                return 1;
                break;
            }
        }
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        {
            if (grid[0][2] == 'O')
            {
                return 0;
                break;
            }
            else if (grid[0][2] == 'X')
            {
                return 1;
                break;
            }
        }
    }
    return 2;
}

bool blankspaces()
{
    int spaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(grid[i][j] == 'O' || grid[i][j] == 'X')
            {
                spaces--;
            }
        }
    }
    if (spaces == 0)
    {
        return true;
        printf("It's a tie!\n");
    }
    else
    {
        return false;
    }
}

bool free_move(int move)
{
     int num = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (num == move)
            {
                if (grid[i][j] == 'O' || grid[i][j] == 'X')
                {
                    printf ("Invalid move.\n");
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                num++;
            }
        }
    }
    return true;
}
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        //for each row
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
        {
            if (grid[i][0] == 'O')
            {
                printf("Congratulations %s, you won!\n", players[0].name);
                return 0;
            }
            else if (grid[i][0] == 'X')
            {
                printf("Congratulations %s, you won!\n", players[1].name);
                return 0;
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
                printf("Congratulations %s, you won!\n", players[0].name);
                return 0;
            }
            else if (grid[0][i] == 'X')
            {
                printf("Congratulations %s, you won!\n", players[1].name);
                return 0;
            }
        }
    }
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    {
        if (grid[0][0] == 'O')
        {
            printf("Congratulations %s, you won!\n", players[0].name);
            return 0;
        }
        else if (grid[0][0] == 'X')
        {
            printf("Congratulations %s, you won!\n", players[1].name);
            return 0;
        }
    }
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        if (grid[0][2] == 'O')
        {
            printf("Congratulations %s, you won!\n", players[0].name);
            return 0;
        }
        else if (grid[0][2] == 'X')
        {
            printf("Congratulations %s, you won!\n", players[1].name);
            return 0;
        }
    }
}
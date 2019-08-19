/**
 * https://quickgrid.wordpress.com/2015/10/29/uva-problem-10189-minesweeper-solution/
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10189 - Minesweeper
 * Technique: 2D Array / Matrix Boundary checking using
 *            if conditions.
 */

#include <stdio.h>
#include <string.h>

#define MAXSIZE 101

static char MineField[MAXSIZE][MAXSIZE];

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;

    int FieldNumber = 0;

    while (scanf("%d%d", &n, &m), n)
    {

        getchar();

        for (int i = 0; i < n; ++i)
            scanf("%s", &MineField[i]);

        if (FieldNumber)
            printf("\n");

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {

                if (MineField[i][j] == '*')
                    continue;

                int temp = 0;

                if (i + 1 < n && MineField[i + 1][j] == '*')
                    ++temp;
                if (i + 1 < n && j + 1 < m && MineField[i + 1][j + 1] == '*')
                    ++temp;
                if (j + 1 < m && MineField[i][j + 1] == '*')
                    ++temp;
                if (i - 1 >= 0 && j + 1 < m && MineField[i - 1][j + 1] == '*')
                    ++temp;
                if (i - 1 >= 0 && MineField[i - 1][j] == '*')
                    ++temp;
                if (i - 1 >= 0 && j - 1 >= 0 && MineField[i - 1][j - 1] == '*')
                    ++temp;
                if (j - 1 >= 0 && MineField[i][j - 1] == '*')
                    ++temp;
                if (i + 1 < n && j - 1 >= 0 && MineField[i + 1][j - 1] == '*')
                    ++temp;

                MineField[i][j] = temp + '0';
            }
        }

        printf("Field #%d:\n", ++FieldNumber);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                putchar(MineField[i][j]);
            printf("\n");
        }
    }

    return 0;
}
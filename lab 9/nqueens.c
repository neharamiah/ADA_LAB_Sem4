#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int n;

void printBoard()
{
    printf("\nOne Solution is:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return 0;
    }

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }

    for(i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

int solveNQueens(int row)
{

    if(row == n)
    {
        printBoard();
        return 1;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {

            board[row][col] = 1;

            if(solveNQueens(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if(!solveNQueens(0))
    {
        printf("No solution exists\n");
    }

    return 0;
}

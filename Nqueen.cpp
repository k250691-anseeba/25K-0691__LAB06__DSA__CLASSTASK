#include <iostream>
using namespace std;

#define N 5

int board[N][N] = {0};

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
}

void solveNQueens(int row)
{
    if (row == N)
    {
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            solveNQueens(row + 1);

            board[row][col] = 0;
        }
    }
}

int main()
{
    solveNQueens(0);

    return 0;
}

#include <iostream>
using namespace std;

bool isSafe(int board[][100], int i, int j, int n)
{
    for (int k = 0; k < n; k++)
    {
        if (board[k][j] == 1)
        {
            return false;
        }
        if (board[i][k] == 1)
        {
            return false;
        }
    }
    int l = i, m = j;
    while (l >= 0 and m >= 0)
    {
        if (board[l][m] == 1)
        {
            return false;
        }
        l--;
        m--;
    }
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
int ans=0;
bool NQueen(int board[][100], int i, int n)
{
    // base case
    if (i == n)
    {
        ans++;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         // board[i][j] == 1 ? cout << "Q" : cout << "_";
        //     }
        //     cout << endl;
        // }
        return false;
    }
    // recursive case

    // Har column par jao
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            bool baakisafe;
            baakisafe = NQueen(board, i + 1, n);
            if (baakisafe == true)
                return true;
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int board[100][100];
    int n;
    cin >> n;
    NQueen(board, 0, n);
    cout<<ans;    
    return 0;
}

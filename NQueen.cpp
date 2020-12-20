#include <iostream>
#include <vector>
using namespace std;
int n;

bool isSafe(vector<vector<int>> mat, int row, int col)
{
    int i, j, k;
    for (i = 0; i <= col; i++)
        if (mat[row][i] == 1)
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 1)
            return false;

    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (mat[i][j] == 1)
            return false;

    return true;
}

bool NQueen(vector<vector<int>> &mat, int col = 0)
{
    if (col >= n)
        return true;
    int i;
    for (i = 0; i < n; i++)
    {
        if (isSafe(mat, i, col) == true)
        {
            mat[i][col] = 1;
            if (NQueen(mat, col + 1) == true)
            {
                return true;
            }
            mat[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout << "Enter size of the matrix  : ";
    cin >> n;
    cout << n << endl;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    if (NQueen(mat) == false)
    {
        cout << "Solution doesn't exist !";
    }
    else
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
}
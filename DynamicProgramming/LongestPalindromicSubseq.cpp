#include <iostream>
#include <vector>
using namespace std;

vector<int> LCS(vector<int> a, vector<int> b)
{
    int m = a.size();
    int n = b.size();
    int i, j, k;

    vector<vector<int>> mat(m + 1, vector<int>(n + 1));
    for (i = 0; i <= m; i++)
        mat[i][0] = 0;
    for (i = 0; i <= n; i++)
        mat[0][i] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
        }
    }

    int length = mat[m][n];
    vector<int> result(length);
    k = length - 1;
    for (i = m, j = n; i > 0 && j >= 0;)
    {
        if (a[i - 1] == b[j - 1])
        {
            result[k] = a[i - 1];
            k--;
            i--;
            j--;
        }
        else if (mat[i - 1][j] >= mat[i][j - 1])
            i--;
        else
            j--;
    }

    return result;
}

vector<int> LPS(vector<int> a)
{
    int m = a.size();
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        b[m - 1 - i] = a[i];
    return LCS(a, b);
}

int main()
{
    int m, n, i;
    cout << "Enter size of sequence A  : ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter Sequence A : ";
    for (i = 0; i < m; i++)
        cin >> a[i];
    vector<int> result = LPS(a);
    for (auto x : result)
        cout << x << " ";
}
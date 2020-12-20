#include <iostream>
#include <vector>
using namespace std;

void Matrix_order(vector<vector<long>> res, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i << " ";
    }
    else
    {
        cout << "( ";
        Matrix_order(res, i, res[i - 1][j - 1]);
        Matrix_order(res, res[i - 1][j - 1] + 1, j);
        cout << ") ";
    }
}

long MatrixMultiplication(vector<int> a, int n)
{
    long l, i, j, k, q;
    vector<vector<long>> mat(n, vector<long>(n, 0));
    vector<vector<long>> res(n, vector<long>(n, 0));
    for (l = 2; l <= n; l++)
    {
        // cout << "***********************l : " << l << endl;
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            mat[i - 1][j - 1] = INT_MAX;
            // cout << " **********i:" << i << " j: " << j << endl;
            for (k = i; k < j; k++)
            {
                q = mat[i - 1][k - 1] + mat[k][j - 1] + a[i - 1] * a[k] * a[j];
                if (mat[i - 1][j - 1] > q)
                {
                    mat[i - 1][j - 1] = q;
                    res[i - 1][j - 1] = k;
                }
                // cout << "k :" << k << "val : " << q << endl;
            }
        }
    }

    for (auto x : mat)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    Matrix_order(res, 1, 6);
    return mat[0][n - 1];
}
int main()
{
    int n, i;
    cout << "Enter no. of matrices : ";
    cin >> n;
    vector<int> a(n + 1);
    cout << "Enter order of matrices : ";
    for (i = 0; i <= n; i++)
        cin >> a[i];
    long res = MatrixMultiplication(a, n);
    cout << "Optimal order of matrix multiplication is : " << res;
}
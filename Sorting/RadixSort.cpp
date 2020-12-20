#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void RadixSort(int arr[], int n)
{
    int i, j, k, dig, max;

    max = arr[0];
    for (i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    dig = 0;
    while (max != 0)
    {
        max /= 10;
        dig++;
    }

    for (i = 1; i <= dig; i++)
    {
        vector<vector<int>> v(10);
        for (j = 0; j < n; j++)
        {
            int pos = (arr[j] / (int)pow(10, i - 1)) % 10;
            v[pos].push_back(arr[j]);
        }
        j = 0;
        for (auto digits : v)
        {
            for (auto values : digits)
            {
                arr[j] = values;
                j++;
            }
        }
    }
}

int main()
{
    int n, i;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    RadixSort(arr, n);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
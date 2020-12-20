#include <iostream>
using namespace std;

void QuickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int i, j, temp, pivot;
        i = lb;
        j = ub;
        while (i < j)
        {
            while (arr[i] <= arr[lb])
                i++;
            while (arr[j] > arr[lb])
                j--;
            if (j < i)
                break;
            else
                swap(arr[i], arr[j]);
        }
        swap(arr[lb], arr[j]);
        QuickSort(arr, lb, j - 1);
        QuickSort(arr, j + 1, ub);
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
    QuickSort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
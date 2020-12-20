#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub);

void MergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{
    int a[mid - lb + 2], b[ub - mid + 1];
    a[mid - lb + 1] = INT_MAX;
    b[ub - mid] = INT_MAX;

    int i = 0, j = 0, k;
    for (i = lb; i <= mid; i++)
    {
        a[j] = arr[i];
        j++;
    }

    j = 0;
    for (i = mid + 1; i <= ub; i++)
    {
        b[j] = arr[i];
        j++;
    }

    i = 0;
    j = 0;
    for (k = lb; k <= ub; k++)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
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
    MergeSort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
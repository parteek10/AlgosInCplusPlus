#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i;
        temp = arr[j];
        while (j > 0 && temp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
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
    InsertionSort(arr, n);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
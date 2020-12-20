#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int min = 0, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
            swap(arr[i], arr[min]);
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
    selectionSort(arr, n);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
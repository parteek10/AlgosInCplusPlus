#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    if (2 * i <= n && arr[largest] < arr[2 * i])
        largest = 2 * i;
    if (2 * i + 1 <= n && arr[largest] < arr[2 * i + 1])
        largest = 2 * i + 1;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    int heapSize = n, i;
    BuildMaxHeap(arr, n);
    for (i = heapSize; i >= 1; i--)
    {
        swap(arr[i], arr[1]);
        heapSize--;
        maxHeapify(arr, heapSize, 1);
    }
}

int main()
{
    int n, i;
    cout << "Enter number of elements in array : ";
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    cout << "Enter elements : ";
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    heapSort(arr, n);
    for (i = 1; i <= n; i++)
        cout << arr[i] << " ";
}
#include <iostream>
#include <vector>
using namespace std;

//using bubble sort
void sort(vector<int> &arr)
{
    int flag = 0, i, j, n;
    n = arr.size();
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int binarySearch(vector<int> arr, int key)
{
    int lb, ub, mid;
    lb = 0;
    ub = arr.size();
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] < key)
            lb = mid + 1;
        else if (arr[mid] > key)
            ub = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr);

    int index, key;
    cout << "enter Value to search : ";
    cin >> key;
    index = binarySearch(arr, key);
    if (index == -1)
        cout << "Element is not present in the list ! ";
    else
        cout << "Element is present at index " << index + 1 << " in the sorted list .";
}
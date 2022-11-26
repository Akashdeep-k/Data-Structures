// Order Agnostic Binary Search
#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    mid = low + (high - low) / 2;

    bool ascending = true;
    if (arr[low] > arr[high])
        ascending = false;

    // searching started
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element && ascending == true)
        {
            low = mid + 1;
        }
        else if (arr[mid] < element && ascending == false)
        {
            high = mid - 1;
        }
        else if (arr[mid] > element && ascending == true)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    // searching ended
    return -1;
}
int main()
{
    int size;
    cout << "Enter the size of array : " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // int size = sizeof(arr)/sizeof(int);
    int element;
    cout << "Enter element you want to search : " << endl;
    cin >> element;
    int pos = binary_search(arr, size, element);
    if (pos != -1)
        cout << "Element is found at position : " << pos + 1 << endl;
    else
        cout << "Element is not present in the array" << endl;
    return 0;
}
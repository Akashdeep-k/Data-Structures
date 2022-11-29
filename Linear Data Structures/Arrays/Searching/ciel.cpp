//To find cieling of a number in array using binary search
//Cieling is defined as number equal or greater than target that should be present in array
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
            return arr[mid];
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
    if(low < size)
    return arr[low];
    else 
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
    cout << "Enter element whose cieling you want to find : " << endl;
    cin >> element;
    int val = binary_search(arr, size, element);
    if(val != -1)
    cout<<"The cieling is : "<<val<<endl;
    else
    cout<<"Cieling not found (out of bounds)"<<endl;
    return 0;
}
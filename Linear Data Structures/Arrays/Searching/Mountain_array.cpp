// Author  :  Akashdeep-k
// Program :  To find peak index in a mountain array
// Examples : 1. array = 1 2 3 4 2 1 (Peak index = 3)
//            2. array = 1 4 10 5 2 (Peak index = 2)
//            3. array = 0 1 0 (Peak index = 1)
#include <iostream>
using namespace std;
int peak(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
        mid = low + (high - low) / 2;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << peak(arr, n);
    return 0;
}
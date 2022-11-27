//To search for a target in a mountain array
#include <iostream>
using namespace std;
int binary_search(int arr[], int low, int high, int element)
{
    int mid;
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
int peak(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s < e){
        if(arr[mid] > arr[mid + 1])
            e = mid;
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return s;
}
int index(int arr[], int n, int target){
    int peakInd = peak(arr, n);
    int left = binary_search(arr, 0, peakInd, target);
    if(left != -1)
        return left;
    else
        return binary_search(arr, peakInd + 1, n - 1, target);
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
    int target;
    cin>>target;
    cout << index(arr, n, target);
    return 0;
}
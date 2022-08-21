// Author : Akashdeep-k
//Program : To find the first occurence of an element
#include <iostream>
using namespace std;
int left(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    int ans;
    while (low <= high)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
        mid = low + (high - low) / 2;
    }
    return ans;
}
int main()
{
    int n, key;
    cin >> n >> key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << left(arr, n, key);
    return 0;
}
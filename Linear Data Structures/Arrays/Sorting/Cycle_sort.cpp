// Cycle Sort
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <iostream>
using namespace std;
void CycleSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] != i + 1)
        {
            swap(arr[arr[i] - 1], arr[i]);
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    CycleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
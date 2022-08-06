// Bubble Sort Technique -
// Time Complexity :
// Best Case : O(n)
// Worst Case : O(n^2)
#include <iostream>
using namespace std;
void Bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Sorting
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++) // Array output
    {
        if (i < n - 1)
            cout << arr[i] << " ";
        else
            cout << arr[n - 1];
    }
}
int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++) // Array Input
    {
        cin >> arr[i];
    }
    Bubble_Sort(arr, n);
    return 0;
}
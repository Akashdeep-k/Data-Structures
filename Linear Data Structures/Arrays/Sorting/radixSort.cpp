//Radix sort implementation
#include <iostream>
using namespace std;
int maxArray(int arr[], int s, int e)
{
    int max = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countSort(int arr[], int s, int e, int dig)
{
    int freq[10] = {0};
    for (int i = s; i <= e; i++)
    {
        freq[(arr[i] / dig) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }
    int output[e + 1];
    for (int i = e; i >= s; i--)
    {
        output[s + --freq[(arr[i] / dig) % 10]] = arr[i];
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int s, int e)
{
    int max = maxArray(arr, s, e);
    for (int dig = 1; max / dig > 0; dig *= 10)
    {
        countSort(arr, s, e, dig);
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
    radixSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
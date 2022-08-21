//Author : Akashdeep-k
//Program : To sort an array containing only 0, 1, 2 with three pointer approach.
#include <iostream>
using namespace std;
void array_print(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;
}
void Sort012(int arr[], int n)
{
    int i = 0;//index for 0
    int j = 0;//index for 1(unknown area)
    int k = n - 1;//index for 2

    while (j <= k)
    {
        switch (arr[j])
        {
        case 0:
            swap(arr[i], arr[j]);
            i++;
            j++;
            break;

        case 1:
            j++;
            break;

        case 2:
            swap(arr[k], arr[j]);
            k--;
            break;
        }
    }
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
    array_print(arr, n);
    Sort012(arr, n);
    array_print(arr, n);
    return 0;
}
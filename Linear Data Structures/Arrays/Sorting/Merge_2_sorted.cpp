// Merging two sorted arrays
#include <iostream>
using namespace std;
void array_print(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<endl;
}
void Merge_Sorted_arrays(int arr[], int brr[], int m, int n)
{
    int crr[m + n];
    int i = 0, j = 0, k = 0;
    while ((i<m)&&(j<n))
    {
        if (arr[i] <= brr[j])
        {
            crr[k++] = arr[i++];
        }
        else
        {
            crr[k++] = brr[j++];
        }
    }
    while(i<m){
        crr[k++] = arr[i++];
    }
    while(j<n){
        crr[k++] = brr[j++];
    }
    array_print(crr, m + n);
}
int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m], brr[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> brr[j];
    }
    Merge_Sorted_arrays(arr, brr, m, n);
    return 0;
}
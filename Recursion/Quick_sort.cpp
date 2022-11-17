#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[e];
    int j = s-1;
    for (int i = s; i < e; i++)
    {
        if(arr[i]<pivot){
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[e]);
    return j+1;
}
void quickSort(int arr[], int s, int e){
    if(s<e){
        int pi = partition(arr, s, e);
        quickSort(arr, s, pi-1);
        quickSort(arr, pi+1, e);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
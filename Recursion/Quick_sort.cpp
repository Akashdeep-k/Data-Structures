#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot)
        count++;
    }
    int pivot_ind = s + count;
    swap(arr[s], arr[pivot_ind]);
    int i = s;
    int j = e;
    while(i < pivot_ind && j > pivot_ind){
        while(arr[i] <= pivot && i < pivot_ind){
            i++;
        }
        while (arr[j] > pivot && j > pivot_ind)
        {
            j--;
        }
        if(arr[i] > pivot && arr[j] <= pivot && i < pivot_ind && j > pivot_ind){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivot_ind;
}
void quick_sort(int arr[], int s, int e){
    if(s>=e){
        return ;
    }
    int pi = partition(arr, s, e);
    quick_sort(arr, s, pi - 1);
    quick_sort(arr, pi + 1, e);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quick_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
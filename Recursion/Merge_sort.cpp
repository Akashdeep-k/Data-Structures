#include<iostream>
using namespace std;
void merge(int *arr, int s, int mid, int e){
    int i = s;
    int j = mid+1;
    int k = s;
    int brr[e+1];
    while((i<=mid)&&(j<=e)){
        if(arr[i] < arr[j]){
            brr[k++] = arr[i++];
        }
        else{
            brr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        brr[k++] = arr[i++];
    }
    while(j<=e){
        brr[k++] = arr[j++];
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = brr[i];
    }
    
}
void merge_sort(int *arr, int s, int e){
    if(s<e){
        int mid = s + (e-s)/2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;
    return 0;
}
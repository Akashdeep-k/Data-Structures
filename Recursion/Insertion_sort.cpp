#include<iostream>
using namespace std;
void insertion_sort(int *arr, int n){
    if(n<=1){
        return ;
    }
    insertion_sort(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    for(;j>=0;j--){
        if(arr[j] > last)
        arr[j+1] = arr[j];
        else{
            break;
        }
    }
    arr[j+1] = last;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;
    return 0;
}
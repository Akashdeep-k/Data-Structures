//To check if an array is sorted or not
#include<iostream>
using namespace std;
bool sorted(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return sorted(arr+1, n-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    if(sorted(arr, n))
    cout<<"sorted";
    else
    cout<<"unsorted";
    return 0;
}
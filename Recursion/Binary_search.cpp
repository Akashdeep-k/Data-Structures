#include<iostream>
using namespace std;
bool binary_search(int arr[], int start, int end, int key){
    if(start>end){
        return false;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid] > key){
        return binary_search(arr, start, mid - 1, key);
    }
    else{
        return binary_search(arr, mid + 1, end, key);
    }
}
int main(){
    int n, key;
    cin>>n>>key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int search = binary_search(arr, 0, n-1, key);
    if(search)
    cout<<"Element found";
    else
    cout<<"Element not found";
    return 0;
}
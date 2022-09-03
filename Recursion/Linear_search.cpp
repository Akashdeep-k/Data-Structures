#include<iostream>
using namespace std;
bool linear_search(int arr[], int n, int key){
    if(n==0)
    return false;
    if(arr[0]==key){
        return true;
    }
    return linear_search(arr + 1, n-1, key);
}
int main(){
    int n, key;
    cin>>n>>key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int search = linear_search(arr, n, key);
    if(search)
    cout<<"Element found";
    else
    cout<<"Element not found";
    return 0;
}
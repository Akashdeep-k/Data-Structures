//Searching in a rotated sorted array
//15, 17 , 20, 5, 12
#include<iostream>
using namespace std;
int binary_search(int arr[], int low, int high, int element)
{
    int mid;
    mid = low + (high-low)/2;
    // searching started
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
         mid = low + (high-low)/2;
    }
    // searching ended
    return -1;
}
int Find_Pivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
    //return e;
}
int searhing(int arr[], int n, int key){
    int pivot = Find_Pivot(arr, n);
    if(key>=arr[pivot]&&key<=arr[n-1]){
        //BS on second line
        return binary_search(arr, pivot, n-1, key);
    }
    else{
        //BS on first line
        return binary_search(arr, 0, pivot-1, key);
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
    cout<<"Index : "<<searhing(arr, n, key);
    return 0;
}
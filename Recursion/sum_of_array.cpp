//To find sum of array elements using recursion
#include<iostream>
using namespace std;
int sum_array(int arr[], int n){
    if(n==0)
    return 0;
    int sum = arr[n-1];
    return (sum + sum_array(arr, n-1));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<sum_array(arr, n);
    return 0;
}
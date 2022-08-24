//Selection sort implementaion 
#include<iostream>
using namespace std;
void array_print(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;
}
void Selection_Sort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
    for (int j = i+1; j < n; j++)
    {
        if(arr[j] < arr[i]){
            swap(arr[j], arr[i]);
        }
    }
    }
    array_print(arr, n);   
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Selection_Sort(arr, n);
    return 0;
}
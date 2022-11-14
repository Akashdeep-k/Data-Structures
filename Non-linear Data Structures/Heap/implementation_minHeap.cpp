//Min heap implementation + insertion
#include<iostream>
using namespace std;
void Insert(int arr[], int i){
    int temp = arr[i];
    while(i > 1 && temp < arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}
int main(){
    cout<<"Enter no. of elements for heap : ";
    int n;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
    cout<<"\nEnter elements for insertion in heap : ";
    for (int i = 1; i < n+1; i++)
    {
        cin>>arr[i];
        Insert(arr, i);
    }
    return 0;
}
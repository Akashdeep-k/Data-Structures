//Deletion in Max heap
#include<iostream>
using namespace std;
void Insert(int arr[], int i){
    //direction of adjustment is from leaf to root
    int temp = arr[i];
    while(i > 1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}
void Delete(int arr[], int n){
    //direction of adjustment is from root to leaf
    int temp = arr[1];
    arr[1] = arr[n];
    int i = 1;
    int j = 2*i;
    while(j < n-1){
        if(arr[j+1] > arr[j])
            j = j + 1;
        if(arr[i] < arr[j]){
        swap(arr[i], arr[j]);
        i = j;
        j = 2*i;
        }
        else{
            break;
        }
    }
    arr[n] = temp;
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
    Delete(arr, n);//will delete the element with max priority
    return 0;
}
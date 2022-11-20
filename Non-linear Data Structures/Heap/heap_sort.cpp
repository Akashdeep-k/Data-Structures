//Sorting elements in increasig order with max heap
#include<iostream>
using namespace std;
void Insert(int arr[], int i){
    int temp = arr[i];
    while(i > 1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp; 
}
void Delete(int arr[], int n){//n is index where last element is present in heap
    int temp = arr[1];
    arr[1] = arr[n];
    int i = 1;
    int j = 2*i;
    while(j < n-1){//j is allowed to iterate till n-2
        if(arr[j+1] > arr[j])
            j = j + 1;//because n-1 will be accessed here
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
    cout<<"Enter no. of elements in heap : ";
    int n;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
    cout<<"\nEnter elements of heap : ";
    for (int i = 1; i < n+1; i++)
    {
        cin>>arr[i];
        Insert(arr, i);
    }
    for (int i = 0; i < n; i++)
    {
        Delete(arr, n - i);//heap size is n-i
    }
    for (int i = 1; i < n+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
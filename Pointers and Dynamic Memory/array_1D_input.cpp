//Input Output of an 1-D array declared dynamically
#include<iostream>
using namespace std;
int main(){
    int n;//length of array
    cin>>n;
    int *arr = new int[n];//declaring int array in heap
    for (int i = 0; i < n; i++)//taking input
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)//printing output
    {
        cout<<arr[i]<<" ";
    }

    //Memory used : 8bytes(pointer, (stack)) + n*4bytes(int array, (heap)) = (n*4 + 8)bytes
    delete(arr);//releasing memory
    return 0;
}
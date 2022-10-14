//Akashdeep-k
//Date and time : 14/10/2022 22:48:00
//Count sort algorithm for sorting in arrays
//Time Complexity : O(n)
//Space Complexity : O(n, max) where n and max are size and maximum element of array
#include<iostream>
using namespace std;
//Count sort with custom indexing for sorting
void countSort(int arr[], int s, int e){
    //Step 1 : Finding max element of array (to make an array of size equal to max element where frequencies of every element can be stored)
    int max = arr[s];
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    //cout<<"Max = "<<max<<endl;

    //Step 2 : storing the freq of every element
    int freq[max+1] = {0};
    for (int i = s; i <= e; i++)
    {
        freq[arr[i]]++;
    }

    // cout<<"Frequency array : ";
    // for (int i = 0; i <= max; i++)
    // {
    //     cout<<freq[i]<<" ";
    // }
    // cout<<endl;
    //Step 3 : modifying the freq array according to freq of previous elements to get the position of last occurence of the elements

    //cout<<"Modified frequency ";
    for (int i = 1; i <= max; i++)
    {
        freq[i] += freq[i-1];
    }
    // for (int i = 0; i <= max; i++)
    // {
    //    cout<<freq[i]<<" ";
    // }
    // cout<<endl;

    //Step 4 : generating a sorted array from the array containing positions of elements

    //cout<<"Step 4 : "<<endl;
    int output[e+1];
    for (int i = e; i >= s; i--)
    {
        // cout<<"The element = "<<arr[i]<<endl;
        // cout<<"Position of element = "<<freq[arr[i]]<<endl;
        output[s + (--freq[arr[i]])] = arr[i];
    }
    // cout<<"Output array : "<<endl;
    // for (int i = 0; i <= e; i++)
    // {
    //     cout<<output[i]<<" ";
    // }
    // cout<<endl;

    //Step 5 : copying the elements in sorted order in original array
    for (int i = s; i <= e; i++)
    {
        arr[i] = output[i];
    }
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    countSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;
    return 0;
}
//To remove duplicates in a sorted array by placing the unique elements in first n slots of the array and then return n.
#include<iostream>
using namespace std;
int RemoveDuplicates_from_SortedArray(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
            int c = 0;
            for(int j = i+1; j < n; j++){
                if(arr[i] == arr[j])
                    c++;
                else
                    break;
            }
            if(c){
            for(int j = i+1; j < n - c; j++){
                arr[j] = arr[j + c];
                }
                n = n - c;
            }
        }
    return n;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<RemoveDuplicates_from_SortedArray(arr, n);
    return 0;
}
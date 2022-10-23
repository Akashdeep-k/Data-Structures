#include<iostream>
#include<cmath>
using namespace std;
int main(){
    //Binary tree implementation by array
    cout<<"Enter the number of levels in binary tree : ";
    int lvl;
    cin>>lvl;

    int total = pow(2, lvl + 1) - 1;
    //Case 1 : storing the elements of tree in array from index 0
    int *arr = new int[total];

    cout<<"Enter the elements level by level from left to right : "<<endl;
    cout<<"Enter -1 if no child "<<endl;
    for (int i = 0; i < total; i++)
    {
        cin>>arr[i];
    }
    int k = 0;
    for (int i = 0; i <= lvl; i++)
    {
        for (int j = 1; j <= pow(2, i); j++)
        {
            if(arr[k] != -1){
                cout<<arr[k]<<" ";
            }
            else{
                cout<<"  ";
            }
            k++;
        }
        cout<<endl;
    }
    
    return 0;
}
//Input Output of an 2-D array declared dynamically
#include<iostream>
using namespace std;
int main(){
    int row;//rows in array
    cin>>row;

    int col;//cols in array
    cin>>col;

    int **arr = new int*[row];//declaring int* array in heap
    for (int i = 0; i <row; i++)
    {
        arr[i] = new int[col];//declaring int array for every int* address in heap
    }
    for (int i = 0; i < row; i++)//taking input
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)//printing output
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memory
    for (int i = 0; i < row; i++)
    {
        delete []arr[i];
    }
    delete []arr;
    return 0;
}
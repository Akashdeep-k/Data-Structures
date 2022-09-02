//Input Output of a variable declared dynamically
#include<iostream>
using namespace std;
int main(){
    int *val = new int;//declaring variable in heap
    cin>>val[0];//taking input
    cout<<val[0]<<endl;//printing output

    //Memory used : 8bytes(pointer, (static)) + 4bytes(int, (dynamic)) = 13bytes 
    delete(val);//releasing memory
    return 0;
}
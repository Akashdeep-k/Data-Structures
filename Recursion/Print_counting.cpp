#include<iostream>
using namespace std;
void descending_order(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    descending_order(n-1);
}
void ascending_order(int n){
    if(n==0){
        return;
    }
    ascending_order(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    descending_order(n);
    cout<<endl;
    ascending_order(n);
    return 0;
}
#include<iostream>
using namespace std;
#define ll long long int    
ll Find_factorial(int n){
    if(n==0){
        return 1;
    }
    return n*Find_factorial(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<Find_factorial(n);
    return 0;
}
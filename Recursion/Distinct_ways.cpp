//Count the number of distinct ways to reach upto n stairs using recursion.
//At each step, you can climb 1 or 2 stairs.
//index starts from 0.
#include<iostream>
using namespace std;
int Distinct_ways(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return Distinct_ways(n-1) + Distinct_ways(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<Distinct_ways(n);
    return 0;
}
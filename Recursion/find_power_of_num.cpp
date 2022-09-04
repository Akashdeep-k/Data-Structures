#include<iostream>
using namespace std;
int find_power(int a, int b){
    if(b==1){
        return a;
    }
    if(b%2==0)
    return find_power(a, b/2)*find_power(a, b/2);
    else
    return a*find_power(a, b/2)*find_power(a, b/2);
}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<find_power(a, b);
    return 0;
}
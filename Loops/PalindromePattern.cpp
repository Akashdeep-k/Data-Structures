/*
for n = 4
          1
        2 1 2
      3 2 1 2 3
    4 3 2 1 2 3 4
*/
#include<iostream>
using namespace std;
void PalindromePattern(int n){
    for (int i = 1; i <= n; i++)
    {
        int j;
        for(j = 1; j <= n-i; j++){
            cout<<"  ";
        }
        int k;
        for (k = i; j <= n; j++)
        {
            cout<<k--<<" ";
        }
        k=2;
        for (; j <= n+i-1; j++)
        {
            cout<<k++<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    PalindromePattern(n);
    return 0;
}
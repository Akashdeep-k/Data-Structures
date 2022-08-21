//Author : Akashdeep-k
//To calculate fibonacci index without recursion
//Time complexity : O(n)
#include<iostream>
using namespace std;
int fib(int n){
    int l=0;//value at last index
    int s_l=0;//value at second last index
    int val=0;//value at present index
    for (int i = 0; i <= n; i++)
    {
        val = l + s_l;
        if(val==0)
        l = 1;
        s_l = l;
        l = val;
    }
    return val;
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
//Time complexity : O(n)
//Space complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    string reversed_str = "";
    while(s.empty() == false){
        reversed_str.push_back(s.top());
        s.pop();
    }
    cout<<reversed_str<<endl;
    return 0;
}
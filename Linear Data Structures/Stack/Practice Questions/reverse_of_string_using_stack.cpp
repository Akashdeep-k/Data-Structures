//Time complexity : O(n)
//Space complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;
void revstr(string &str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    str = "";
    while(s.empty() == false){
        str.push_back(s.top());
        s.pop();
    }
}
int main(){
    string str;
    cin>>str;
    revstr(str);
    cout<<str;
    return 0;
}
//To check a string has valid parenthesis or not 
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
        bool val = true;
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    val = false;
                    break;
                }
                if(st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' || st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else{
                    val = false;
                    break;
                }
            }
        }
        if(st.empty() && val)
            return true;
        else
            return false;
    }
int main(){
    cout<<"Enter a string consisting of parenthesis : "<<endl;
    cout<<"eg. {}(){{[]}()}"<<endl;
    cout<<"Input = ";
    string str;
    cin>>str;
    cout<<boolalpha<<isValid(str);
    return 0;
}
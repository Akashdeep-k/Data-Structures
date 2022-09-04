#include<iostream>
#include<string>
using namespace std;
void reverse(string &str, int s){
    if(s>=str.length()/2){
        return;
    }
    else{
        swap(str[s], str[str.length() - s - 1]);
        reverse(str, ++s);
    }
}
int main(){
    string str;
    cin>>str;
    reverse(str, 0);
    cout<<str;
    return 0;
}
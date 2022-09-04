#include<iostream>
#include<string>
using namespace std;
bool check_palindrome(string str, int s = 0){
    if(s>=str.length()/2){
        return true;
    }
    if(str[s] == str[str.length() - s - 1]){
        return check_palindrome(str, ++s);
    }
    else{
        return false;
    }
}
int main(){
    string str;
    cin>>str;
    bool check = check_palindrome(str);
    if(check)
    cout<<"Yes, the word is a palindrome!";
    else
    cout<<"No, the word is not a palindrome!";
    return 0;
}
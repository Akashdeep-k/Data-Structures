//To check if a string is palindrome or not 
//Not case sensitive
//consider alphanumeric characters
//ignore white spaces and special characters
#include<iostream>
#include<string>
using namespace std;
bool Valid_character(char ch){
    if((ch>='a'&&ch<='z')||(ch>='1'&&ch<='9')||(ch>='A'&&ch<='Z')){
        return true;
    }
    return false;
}
char ToLowerCase(char ch){
    if((ch>='a'&&ch<='z')||(ch>='1'&&ch<='9')){
        return ch;
    }
    else{
        return ch - 'A' + 'a';
    }
}
bool Palindrome(string str){
    for (int i = 0; i < str.length()/2; i++)
    {
        if(str[i]!=str[str.length()-1-i]){
            return false;
        }
    }
    return true;
}
void Check_palindrome(string str){
    string temp = "";
    for(int i = 0; i < str.length(); i++){
        if(Valid_character(str[i])){
            temp.push_back(str[i]);
        }
    }
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = ToLowerCase(temp[i]);
    }
    
    if(Palindrome(temp)){
        cout<<str<<" & "<<temp<<" is palindrome"<<endl;
    }
    else{
        cout<<str<<" & "<<temp<<" is not a palindrome"<<endl;
    }
}
int main(){
    string str;
    getline(cin, str);
    Check_palindrome(str);
    return 0;
}
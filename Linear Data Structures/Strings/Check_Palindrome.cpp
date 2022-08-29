//To check if a string is palindrome or not 
//Not case sensitive
//Eg : HelloOLLeh is a Palindrome
#include<iostream>
using namespace std;
int Length_of_string(string str){
    int len = 0;
    for (int i = 0; str[i]!= '\0'; i++)
    {
        len++;
    }
    return len;
}
char ToLowerCase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    else{
        return ch - 'A' + 'a';
    }
}
bool Palindrome(string str, int len){
    for (int i = 0; i < len/2; i++)
    {
        if(str[i]!=str[len-1-i]){
            return false;
        }
    }
    return true;
}
void Check_palindrome(string str){
    int len = Length_of_string(str);
    for(int i = 0; i < len; i++){
        str[i] = ToLowerCase(str[i]);
    }
    if(Palindrome(str, len)){
        cout<<"The string is palindrome"<<endl;
    }
    else{
        cout<<"The string is not a palindrome"<<endl;
    }
}
int main(){
    string str;
    cin>>str;
    Check_palindrome(str);
    return 0;
}
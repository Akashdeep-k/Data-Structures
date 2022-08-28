//To reverse a sting 
#include<iostream>
using namespace std;
int length_of_string(string s){
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        c++;
    }
    return c;
}
void reverse(string str){
    int n = length_of_string(str);
    for (int i = 0; i < n/2; i++)
    {
        swap(str[i], str[n-1-i]);
    }
    cout<<str;
}
int main(){
    string str;
    cin>>str;
    reverse(str);
    return 0;
}
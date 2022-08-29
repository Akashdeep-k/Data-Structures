//To reverse words in a string
#include<iostream>
using namespace std;
void reverse(string str){
    for (int i = 0; i < str.length()/2; i++)
    {
        swap(str[i], str[str.length()-1-i]);
    }
    cout<<str<<" ";
}
void Reverse_words(string str){
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        temp.push_back(str[i]);
        if((str[i+1] == ' ')||(str[i+1] == '\0')){
            reverse(temp);
            temp = "";
            i++;//to skip the space
        }
    }
}
int main(){
    string str;
    getline(cin, str);
    Reverse_words(str);
    return 0;
}
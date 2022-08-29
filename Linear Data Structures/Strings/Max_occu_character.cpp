//To print the max occuring character in a string 
//Case Insensitive
#include<iostream>
using namespace std;
char To_lowercase(char ch){
    if(ch>='a'&&ch<='z')
    return ch;
    else
    return ch - 'A' + 'a';
}
char MaxOccuCharacter(string str){
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = To_lowercase(str[i]);
    }
    int arr[26] = {0};
    int max = -1;
    int index = -1;
    for (int i = 0; i < str.length(); i++)
    {
        int num = str[i] - 'a';
        arr[num]++;
        if(max<=arr[num]){
            max = arr[num];
            index = num;
        }
    }
    return index + 'a';
}
int main(){
    string str;
    cin>>str;
    cout<<MaxOccuCharacter(str);
    return 0;
}
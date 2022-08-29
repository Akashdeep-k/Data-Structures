//Replace spaces with @40
//used resize function to change the string length
#include<iostream>
using namespace std;
void Replace_spaces(string str){
    //counted the no. of spaces
    int co = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' '){
            co++;
        }
    }
    //space will be replaced by three characters but space will be overridden by only one character so for other two characters the size of string is increased depending on no. of spaces.
    str.resize(str.length() + 2*co);

    //traversing the whole string
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' '){//space occured at i index
        
        //shifted every character after space by two indices to the right
            for (int j = str.length(); j >= i+3; j--)//because space occured at i so bound will be i+3.
            {
                str[j] = str[j-2];
            }
            str[i] = '@';//space replace by @
            str[i+1] = '4';
            str[i+2] = '0';
        }
    }

    //Modified string
    cout<<str;
}
int main(){
    string str;
    getline(cin, str);
    Replace_spaces(str);
    return 0;
}
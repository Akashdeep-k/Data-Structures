//To find length of a string
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
int main(){
    string s;
    getline(cin, s);
    cout<<length_of_string(s)<<endl;
    return 0;
}
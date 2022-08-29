//To remove all the occurences of a sub string from a main string
//used erase function to remove substring 
#include<iostream>
#include<string>
using namespace std;
void remove_substr(string main, string sub){
    while(main.length()!=0 && sub.length() < main.length()){
        main.erase(main.find(sub), sub.length());
    }
    cout<<main<<endl;
}
int main(){
    string main, sub;
    cin>>main>>sub;
    remove_substr(main, sub);
    return 0;
}

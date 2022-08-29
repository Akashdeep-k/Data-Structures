//To remove all the occurences of a sub string from a main string
//used erase function to remove substring 
#include<iostream>
#include<string>
using namespace std;
void remove_substr(string main, string sub){

    //traversed the main string
    for (int i = 0; i < main.length(); i++)
    {
        //if a character of main string matches with the first character of sub string
        if(main[i] == sub[0]){
            bool eq = true;//assumed the next characters are equal to sub string

            //traversed sub string and compared with main string after ith index
            for (int j = 1; j < sub.length(); j++)
            {
                if(sub[j] != main[i+j]){
                    eq = false;//if sub string not found in main string
                    break;
                }
            }

            //erase if eq == true
            if(eq){
                main.erase(i, sub.length());
                i--;//as ith index is also removed and another character is placed at ith index so check ith index again
            }
            else{
                //sub string not found in main string
                //continue traversing
            }
        }
    }
    //modified main string
    cout<<main<<endl;
}
int main(){
    string main, sub;
    cin>>main>>sub;
    remove_substr(main, sub);
    return 0;
}

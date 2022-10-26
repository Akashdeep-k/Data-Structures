#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int> &q){
    if(q.empty()){
        return ;
    }
    int f = q.front();
    q.pop();
    reverse(q);
    q.push(f);
}
int main(){
    queue<int> q;
    while(1){
        cout<<"Do you want to insert an element in queue : "<<endl;;
        cout<<"Enter y/n : ";
        char ch;
        cin>>ch;
        if(ch == 'y'){
            cout<<"Enter the element : ";
            int d;
            cin>>d;
            q.push(d);
        }
        else{
            break;
        }
    }
    cout<<"The reversed queue is : ";
    reverse(q);
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}
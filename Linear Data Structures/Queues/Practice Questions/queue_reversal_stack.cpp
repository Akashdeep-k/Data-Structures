#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    queue<int> q;
    stack<int> s;
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
    while(!q.empty()){
        //cout<<"Pushing "<<q.front()<<" into the stack"<<endl;
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        //cout<<"Pushing "<<s.top()<<" into the queue"<<endl;
        q.push(s.top());
        s.pop();
    }
    
    cout<<"The reversed queue is : ";
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
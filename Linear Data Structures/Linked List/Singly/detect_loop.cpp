#include<iostream>
#include<map>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
bool detect_loop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*, bool> visited;
    while(head!=NULL){
        if(visited[head]==true){
            return true;
        }
        visited[head] = true;
        head = head->next;
    }
    return false;
}
int main(){
    Node* head;
    if(detect_loop(head)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
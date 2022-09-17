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
bool detect_loop(Node* &head){
    if(head==NULL)
    return false;
    else{
        Node* fast = head;
        Node* slow = head;
        while(slow!=NULL && fast!=NULL){
            fast = fast->next;
            if(fast!=NULL)
            fast = fast->next;
            slow = slow->next;
            if(slow == fast)
            return true;
        }
        return false;
    }
}
int main(){
    Node* head;
    //make a linked list
    if(detect_loop(head)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
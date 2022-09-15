#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node(){}
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void creation(node* &head, int d){
    node* n = new node(d);
    node* temp = head;
    if(head==NULL){
        head = n;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
            temp->next = n;
    }
}
void reverse(node* &head){
    if(head==NULL||head->next==NULL){
        return;
    }
    node* curr = head;
    node* prev = NULL;
    node* forw = NULL;
    while(curr!=NULL){
    forw = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forw;
    }
    head = prev;
}
void traversal(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin>>d;
        creation(head, d);
    }
    traversal(head);
    reverse(head);
    traversal(head);
    return 0;
}
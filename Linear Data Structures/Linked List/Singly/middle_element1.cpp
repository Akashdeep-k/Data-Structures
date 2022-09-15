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
void traversal(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void getmiddle(node* head){
    node* temp = head;
    while(head->next!=NULL){
        head = head->next;
        if(head->next!=NULL)
        head = head->next;
        temp = temp->next;
    }
    cout<<"The middle element is : "<<temp->data<<endl;
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
    getmiddle(head);
    return 0;
}
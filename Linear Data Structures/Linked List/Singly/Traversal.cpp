#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* link;
    node(){}
    node(int data){
        this->data = data;
        this->link = NULL;
    }
};
void traversal(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;    
}
void insertion(node* &head, int d){
    node* n = new node(d);
    if(head==NULL){
        head = n;
    }
    else{
        node* temp = head;
        while(temp->link!=NULL){
            temp = temp->link;
        }
            temp->link = n;
    }
}
int main(){
    node* head = NULL;
    int n, d;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>d;
        insertion(head, d);
    }
    traversal(head);
    return 0;
}
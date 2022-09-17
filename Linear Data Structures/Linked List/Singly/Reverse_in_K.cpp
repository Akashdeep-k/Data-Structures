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
void traversal(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void creation(node* &head, int d){
    node* n = new node(d);
    if(head == NULL){
        head = n;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}
node* reverse_in_k(node* &head, int k){
    if(head==NULL){
        return head;
    }
    node* prev = NULL;
    node* forw = NULL;
    node* curr = head;
    int count = 0;
    while(curr!=NULL&&count < k){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        count++;
    }
    if(forw!=NULL){
        head->next = reverse_in_k(forw, k);
    }
    return prev;
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
    head = reverse_in_k(head, 3);
    traversal(head);
    return 0;
}
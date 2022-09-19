#include<iostream>
using namespace std;
//Akashdeep-k
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
void creation(node* &tail, int d){
    node* n = new node(d);
    if(tail == NULL){
        tail = n;
        n->next = n;
    }
    else{
        node* temp = tail->next;
        while(temp != tail){
            temp = temp->next;
        }
        n->next = tail->next;
        tail->next = n;
        tail = tail->next;
    }
}
void traversal(node* &tail){
    node* head = tail->next;
    while(head!=tail){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data;
    cout<<endl;
}
int get_length(node* tail){
    node* temp = tail->next;
    int len = 0;
    while(temp!=tail){
        len++;
        temp = temp->next;
    }
    return len+1;
}
pair<node* , node* > breaking_function(node* &tail){
    int len = get_length(tail);
    node* forw = NULL;
    node* temp = tail->next;
    int i = 1;
    while(i!=len/2){
        temp = temp->next;
        i++;
    }
    forw = temp->next;
    temp->next = tail->next;
    tail->next = forw;
    pair<node* , node* > tails(temp, tail);
    return (tails);
}
int main(){
    node* tail = NULL;
    int n;
    cin>>n;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin>>d;
        creation(tail, d);
    }
    cout<<"Original : "<<endl;
    traversal(tail);

    pair<node* , node* > tails = breaking_function(tail);
    cout<<"First Circular list : "<<endl;
    traversal(tails.first);
    cout<<"Second Circular list : "<<endl;
    traversal(tails.second);
    return 0;
}
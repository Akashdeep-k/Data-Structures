//Sorting 0, 1, and 2 in a linked list using data replacement
//Time complexity : O(n)
//Space complexity : O(1)
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
void sort012(node* &head){
    node* temp = head;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    while(temp!=NULL){
        if(temp->data==0)
        count_0++;
        if(temp->data==1)
        count_1++;
        if(temp->data==2)
        count_2++;
        temp = temp->next;
    }
    //replacing
    temp = head;
    while(temp!=NULL){
        if(count_0){
            temp->data = 0;
            count_0--;
        }
        else if(count_1){
            temp->data = 1;
            count_1--;
        }
        else{
            temp->data = 2;
            count_2--;
        }
        temp = temp->next;
    }
}
int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int d;
    for (int i = 0; i < n; i++)
    {
        //Enter only 0, 1, or 2;
        cin>>d;
        creation(head, d);
    }
    traversal(head);
    sort012(head);
    traversal(head);
    return 0;
}
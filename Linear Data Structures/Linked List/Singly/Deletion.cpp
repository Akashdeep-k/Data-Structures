//Deletion in a linked list - beginning, between, end, specific value
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* link;
};
void linkedlist_traversal(node* head){
    node* ptr = head;
    while (ptr!=NULL)
    {
    cout<<ptr->data<<endl;
    ptr = ptr->link;
    }
}
node* deletion_beg(node* head){
    node* ptr = head;
    head = head->link;
    free(ptr);
    return head;
}
node* deletion_between(node* head, int index){
    node* a = head;
    node* b = head->link;
    int i = 0;
    while(i<index-1){
        a=a->link;
        b=b->link;
        i++;
    }
    a->link=b->link;
    free(b);
    return head;
}
node* deletion_end(node* head){
    node* a = head;
    node* b = head->link;
    while(b->link!=NULL){
        a=a->link;
        b=b->link;
    }
    a->link=NULL;
    free(b);
    return head;
}
node* deletion_key(node* head, int key){
    node* a = head;
    node* b = head->link;
    while (b->data!=key)
    {
        a = a->link;
        b = b->link;
    }
    a->link = b->link;
    free(b);
    return head;
}
int main()
{
    node* head = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;

    head->data=5;
    head->link = second;

    second->data=7;
    second->link = third;

    third->data=9;
    third->link = fourth;

    fourth->data=11;
    fourth->link=NULL;

    head = deletion_key(head, 9);
    linkedlist_traversal(head);
    return 0;
}
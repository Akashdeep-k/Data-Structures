#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {}
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert(node *&tail, int element, int d)
{
    node *temp = tail;
    node *n = new node(d);
    if (tail == NULL)
    {
        n->next = n;
        tail = n;
    }
    else
    {
        while (temp->data != element)
        {
            temp = temp->next;
        }
        if(temp != tail){
        n->next = temp->next;
        temp->next = n;
        }
        else{
            temp->next = n;
            n->next = n;
            tail = n;
        }
    }
}
void traverse(node* &tail){
    node* temp = tail->next;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}
int main()
{
    node* tail = NULL;
    insert(tail, 45, 4);
    insert(tail, 4, 5);
    insert(tail, 5, 6);
    insert(tail, 6, 7);
    // insert(tail, , 4);
    // insert(tail, 45, 4);
    // insert(tail, 45, 4);
    traverse(tail);
    
    return 0;
}
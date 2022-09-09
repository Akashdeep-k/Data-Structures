#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node() {}
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void traversal(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insert_at_head(node* &head, int d)
{
    node *n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
}
void insert(node* &head, int d, int ind)
{

    if (ind == 0)
    {
        insert_at_head(head, d);
    }
    else
    {
        node *temp = head;
        node *n = new node(d);
        int i = 0;
        while (i != ind - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next != NULL)
        {
            n->next = temp->next;
            temp->next->prev = n;
            temp->next = n;
            n->prev = temp;
        }
        else
        {
            temp->next = n;
            n->prev = temp;
        }
    }
}
int main()
{
    node* head;
    node* first = new node(5);
    head = first;
    traversal(head);
    insert(head, 4, 1);
    insert(head, 3, 0);
    insert(head, 7, 2);
    insert(head, 8, 1);
    traversal(head);
    return 0;
}
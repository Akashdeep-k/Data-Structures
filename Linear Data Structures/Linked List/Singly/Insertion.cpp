// Insertion - 1.At beginning, 2.In  between, 3.At end, 4.After a node
// Time Complexity - O(1), O(n), O(n), O(1) (are in order)
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};
// Linked list traversal
void linkedlist_traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}
// Insertion at beginning
node *Insertion_beginning(int data, node *head)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->link = head;
    return ptr;
}
// Insertion in between
node *Insertion_between(node *head, int data, int index)
{
    node *ptr = new node;
    ptr->data = data;
    node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->link;
        i++;
    }

    ptr->link = p->link;
    p->link = ptr;
    return head;
}
// Insertion at end
node *Insertion_end(node *head, int data)
{
    node *ptr = new node;
    ptr->data = data;

    node *p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = ptr;
    ptr->link = NULL;
    return head;
}
// Insertion after a node
node *Insertion_after_node(node *prev_node, int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->link = prev_node->link;
    prev_node->link = ptr;
    return prev_node;
}
int main()
{
    node *head = new node;
    node *second = new node;
    node *third = new node;

    head->data = 5;
    head->link = second;

    second->data = 7;
    second->link = third;

    third->data = 9;
    third->link = NULL;

    // Insertion at beginning
     head = Insertion_beginning(7, head);
     linkedlist_traversal(head);

    // Insertion in between
    //  head = Insertion_between(head, 11, 1);
    //  linkedlist_traversal(head);

    // Insertion at end
    //  head = Insertion_end(head, 11);
    //  linkedlist_traversal(head);

    // Insertion after a node
    //  second = Insertion_after_node(second, 12);
    //  linkedlist_traversal(head);
    return 0;
}
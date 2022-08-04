//Linked List Traversal
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};
void linkedlist_traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}
int main()
{
    node *head = new node;
    node *second = new node;
    node *third = new node;
    // Creating a link between first and second
    head->data = 5;
    head->link = second;
    // Creating a link between second and third
    second->data = 7;
    second->link = third;

    third->data = 9;
    third->link = NULL;
    linkedlist_traversal(head);
    return 0;
}
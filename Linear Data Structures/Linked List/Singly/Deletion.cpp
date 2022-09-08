#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node() {}
    node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};
void traversal(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}
void deletion(node *&head, int index)
{
    if (index == 0)
    {
        node *ptr = head;
        head = head->link;
        free(ptr);
    }
    else
    {
        node *temp = head;
        int i = 0;
        while (i != index - 1)
        {
            temp = temp->link;
            i++;
        }
        node *curr = temp->link;
        temp->link = curr->link;
        curr->link = NULL;
        free(curr);
    }
}
int main()
{
    node *head;
    node *first = new node(5);
    node *second = new node(10);
    node *third = new node(15);
    node *fourth = new node(20);
    node *fifth = new node(25);

    head = first;
    first->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = NULL;

    traversal(head);
    deletion(head, 2);
    traversal(head);
    deletion(head, 0);
    traversal(head);
    deletion(head, 0);
    traversal(head);
    return 0;
}
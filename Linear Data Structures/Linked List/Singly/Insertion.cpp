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
void insertion(node *&head, int d, int ind)
{
    node *n = new node(d);
    //insertion at beginning
    if (ind == 0)
    {
        n->link = head;
        head = n;
    }
    else
    {
        node *temp = head;
        int i = 0;
        while (i != ind - 1)
        {
            temp = temp->link;
            i++;
        }
        //insertion in the middle
        if (temp->link != NULL)
        {
            n->link = temp->link;
            temp->link = n;
        }
        //insertion in the end
        else
        {
            temp->link = n;
        }
    }
}
int main()
{
    node *head = NULL;
    int n, d, ind;
    cout << "Enter length : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data and valid index : " << endl;
        cin >> d >> ind;
        insertion(head, d, ind);
    }
    traversal(head);
    return 0;
}
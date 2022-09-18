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
void creation(node *&head, int d)
{
    node *n = new node(d);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
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
void delete_duplicate(node* &head){
    if(head == NULL || head->next == NULL)
    return;

    node* curr = head;
    while(curr->next!=NULL){
        node* temp = curr;
        while(temp->next!=NULL){
            if(curr->data == temp->next->data && temp->next != NULL){
                node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else{
                temp = temp->next;
            }
        }
        if(curr->next!=NULL)
        curr = curr->next;
    }
}
int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        // insert elements in unsorted order
        creation(head, d);
    }
    traversal(head);
    delete_duplicate(head);
    traversal(head);
    return 0;
}
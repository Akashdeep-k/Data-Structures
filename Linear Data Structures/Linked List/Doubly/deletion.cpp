#include<iostream>
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
void creation(node* &head, int d){
    node* n = new node(d);
    if(head==NULL){
        head = n;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}
void deletion(node* &head, int ind){
    node* temp = head;
    if(ind==0){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else{
        int i = 0;
        while(i != ind-1){
            temp = temp->next;
            i++;
        }
        node* curr = temp->next;
        curr->prev = NULL;
        temp->next = curr->next;
        curr->next = NULL;
        //temp->next->prev = temp;
        delete(curr);
    }
}
int main(){
    node* head = NULL;
    int n;
    cout<<"Enter number of elements : "<<endl;
    cin>>n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter value : ";
        cin>>num;
        creation(head, num);
    }
    traversal(head);
    deletion(head, 3);
    traversal(head);
    deletion(head, 1);
    traversal(head);
    deletion(head, 2);
    traversal(head);
    deletion(head, 0);
    traversal(head);
    deletion(head, 5);
    traversal(head);
    return 0;
}
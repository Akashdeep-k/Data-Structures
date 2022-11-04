//Problem : Convert BST into sorted linked list
#include<iostream>
#include<vector>
using namespace std;
class node{
    public :
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class list{
    public :
    int data;
    list* next;
    list(int data){
        this->data = data;
        this->next = NULL;
    }
};
list* MakeList(list* head, int data){
    if(head == NULL){
        head = new list(data);
        return head;
    }
    else{
        list* OriginalHead = head;
        while(head->next != NULL){
            head = head ->next;
        }
        head->next = new list(data);
        return OriginalHead;
    }
}
node* InsertData(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->data){
        root->left = InsertData(root->left, data);
    }
    if(data > root->data){
        root->right = InsertData(root->right, data);
    }

    return root;
}
node* CreateBst(node* root){
    int data;
    cin>>data;
    while (data != -1)
    {
        root = InsertData(root, data);
        cin>>data;
    }
    return root;
}
void InOrder(node* root, vector<int> &SortedBst){
    if(root == NULL){
        return;
    }
    InOrder(root->left, SortedBst);
    SortedBst.push_back(root->data);
    InOrder(root->right, SortedBst);
}
void DisplayList(list* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
list* PushDataIntoList(list* head, vector<int> SortedBst){
    for (int i = 0; i < SortedBst.size(); i++)
    {
        head = MakeList(head, SortedBst[i]);
    }
    return head;
}
int main(){
    node* root = NULL;
    list* head = NULL;
    root = CreateBst(root);
    vector<int> SortedBst;
    InOrder(root, SortedBst);
    head = PushDataIntoList(head, SortedBst);
    DisplayList(head);
    return 0;
}
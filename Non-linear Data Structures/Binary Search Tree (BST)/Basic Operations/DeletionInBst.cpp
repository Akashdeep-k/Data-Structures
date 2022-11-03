//Deletion of an element from BST
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *MakeBst(node *root, int d)
{
    if (root == NULL)
    {
        node *temp = new node(d);
        return temp;
    }

    if (d < root->data)
    {
        root->left = MakeBst(root->left, d);
    }
    else if (d > root->data)
    {
        root->right = MakeBst(root->right, d);
    }
    return root;
}
node* GiveMeData(node *root)
{
    int d;
    while (1)
    {
        cin >> d;
        if (d == -1)
            break;
        else
            root = MakeBst(root, d);
    }
    return root;
}
void InOrder(node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
int MinElementInBst(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
node* DeletionInBst(node* root, int key){
    if(root == NULL)
    return NULL;

    if(root->data > key)
        root->left = DeletionInBst(root->left, key);
    else if(root->data < key)
        root->right = DeletionInBst(root->right, key);
    else{
        //0 child
        if(root->left == NULL && root->right == NULL){
            //cout<<"The node has no child"<<endl;
            delete root;
            return NULL;
        }
        //1 child
        else if(root->left == NULL || root->right == NULL){
            if(root->left != NULL){
                node* next = root->left;
                delete root;
                return next;
            }
            if(root->right != NULL){
                //cout<<"The child of node is "<<root->right->data<<endl;
                node* next = root->right;
                delete root;
                return next;
            }
        }
        //2 child
        else{
            int min = MinElementInBst(root->right);
            root->data = min;
            root->right = DeletionInBst(root->right, min);
        }
    }
    return root;
}
int main()
{
    node *root = NULL;
    root = GiveMeData(root);
    InOrder(root);
    cout<<endl;
    int key;
    cin>>key;
    DeletionInBst(root, key);
    InOrder(root);
    cout<<endl;
    return 0;
}
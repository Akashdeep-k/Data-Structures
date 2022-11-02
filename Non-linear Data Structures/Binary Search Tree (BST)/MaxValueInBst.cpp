//To find the maximum value in BST
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
int MaxElementInBst(node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}
int main()
{
    node *root = NULL;
    root = GiveMeData(root);
    //InOrder(root);
    //cout<<endl;
    cout<<MaxElementInBst(root);
    return 0;
}
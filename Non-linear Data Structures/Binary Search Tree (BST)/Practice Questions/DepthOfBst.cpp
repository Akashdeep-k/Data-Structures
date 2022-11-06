//To find the depth of a BST using recursion
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
int DepthOfBst(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(DepthOfBst(root->left), DepthOfBst(root->right));
}
int main(){
    node* root = NULL;
    root = GiveMeData(root);
    cout<<DepthOfBst(root);
}
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
int MaxElementInBst(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int MinElementInBst(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
pair<int, int> InorderPredecessorAndSuccessor(node *root, int key)
{
    if (root == NULL)
        return {-1, -1};
    if (root->data > key)
        return InorderPredecessorAndSuccessor(root->left, key);
    if (root->data < key)
        return InorderPredecessorAndSuccessor(root->right, key);
    if (root->data == key)
        return {MaxElementInBst(root->left), MinElementInBst(root->right)};
}

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
int main()
{
    node *root = NULL;
    // make a BST and update the root
    root = GiveMeData(root);
    InOrder(root);
    cout<<endl;
    int key;
    cin >> key; // key should be present in the bst
    pair<int, int> pre_suc = InorderPredecessorAndSuccessor(root, key);
    cout << pre_suc.first << " " << pre_suc.second << endl;
    return 0;
}
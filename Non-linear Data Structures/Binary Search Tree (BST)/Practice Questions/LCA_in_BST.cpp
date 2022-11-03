// Input - You are given data of two nodes of BST
// Find the Lowest Common Ancestor (LCA) among the nodes
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
int LCA(node *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data > a && root->data > b)
    {
        return LCA(root->left, a, b);
    }
    else if (root->data < a && root->data < b)
    {
        return LCA(root->right, a, b);
    }
    else
    {
        return root->data;
    }
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
node *GiveMeData(node *root)
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
int main()
{
    node *root = NULL;
    root = GiveMeData(root);
    int key1, key2;
    cin >> key1 >> key2;
    cout << LCA(root, key1, key2);
    return 0;
}
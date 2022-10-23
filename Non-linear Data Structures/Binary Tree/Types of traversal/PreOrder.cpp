#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node() {}
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *creation(node *root)
{
    cout << "Enter the data (-1 for NULL) : ";
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    else
    {
        root = new node(d);
        cout << "Enter the data for left child of " << d << endl;
        root->left = creation(root);
        cout << "Enter the data for right child of " << d << endl;
        root->right = creation(root);
        return root;
    }
}
void PreOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
int main()
{
    node *root = NULL;
    root = creation(root);
    cout << "The pre-order traversal is : ";
    PreOrder(root);
    return 0;
}
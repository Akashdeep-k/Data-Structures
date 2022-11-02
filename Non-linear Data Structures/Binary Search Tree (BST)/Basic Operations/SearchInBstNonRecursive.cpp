//Searching element in BST
//Return true if element is present
//Return false if element is not present
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
void InOrder(node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
bool SearchInBst(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return true;
        if (root->data > key)
            root = root->left;
        if (root->data < key)
            root = root->right;
    }
    return false;
}
int main()
{
    node *root = NULL;
    root = GiveMeData(root);
    InOrder(root);
    cout << endl;
    int key;
    cin >> key;
    cout << boolalpha << SearchInBst(root, key);
    return 0;
}
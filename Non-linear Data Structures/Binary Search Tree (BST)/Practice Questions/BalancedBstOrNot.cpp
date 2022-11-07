// To check a given Bst is balanced or not
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
int Depth(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(Depth(root->left), Depth(root->right));
}
bool BalancedBstOrNot(node *root)
{
    if(root == NULL)
        return true;
    if (abs(Depth(root->left) - Depth(root->right)) > 1)
        return false;
    bool l = BalancedBstOrNot(root->left);
    bool r = BalancedBstOrNot(root->right);
    return l && r;
}
int main()
{
    node *root = NULL;
    root = GiveMeData(root);
    cout << boolalpha << BalancedBstOrNot(root) << endl;
    return 0;
}
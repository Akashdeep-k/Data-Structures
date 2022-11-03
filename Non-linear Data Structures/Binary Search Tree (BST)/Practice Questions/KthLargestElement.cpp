// To find Kth largest element in a BST
// where K is natural number less than equal to total number of nodes in BST
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
int ReverseInOrderUptoK(node *root, int &curr, int k)
{
    if (root == NULL)
        return -1;

    int right = ReverseInOrderUptoK(root->right, curr, k);
    if (right != -1)
        return right;
    ++curr;
    if (curr == k)
        return root->data;
    int left = ReverseInOrderUptoK(root->left, curr, k);
}
int KthSmallestElement(node *root, int k)
{
    int curr = 0;
    return ReverseInOrderUptoK(root, curr, k);
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
    int k;
    cin >> k;
    cout<<KthSmallestElement(root, k);
    return 0;
}
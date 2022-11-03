// To find Kth smallest element in a BST
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
int InOrderUptoK(node *root, int &curr, int k)
{
    if (root == NULL)
        return -1;

    int left = InOrderUptoK(root->left, curr, k);
    if (left != -1)
        return left;
    ++curr;
    if (curr == k)
        return root->data;
    int right = InOrderUptoK(root->right, curr, k);
}
int KthSmallestElement(node *root, int k)
{
    int curr = 0;
    return InOrderUptoK(root, curr, k);
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
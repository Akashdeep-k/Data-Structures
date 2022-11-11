// To find minimum difference between two nodes of a BST
#include <iostream>
#include <vector>
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
void InOrder(node *root, vector<int> &sort)
{
    if (root == NULL)
        return;

    InOrder(root->left, sort);
    sort.push_back(root->data);
    InOrder(root->right, sort);
}
int MinDiffInBST(node *root)
{
    vector<int> sort;
    InOrder(root, sort);
    int n = sort.size();
    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if ((sort[i + 1] - sort[i]) < min)
        {
            min = sort[i + 1] - sort[i];
        }
    }

    return min;
}
int main()
{

    return 0;
}
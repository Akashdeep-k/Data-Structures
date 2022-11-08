// To convert a normal Bst into a balanced Bst
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *MakeBst(Node *root, int d)
{
    if (root == NULL)
    {
        Node *temp = new Node(d);
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
Node *GiveMeData(Node *root)
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
void InOrder(Node *root, vector<int> &sort)
{
    if (root == NULL)
        return;

    InOrder(root->left, sort);
    sort.push_back(root->data);
    InOrder(root->right, sort);
}
Node *NormalBstToBalancedBst(vector<int> &sort, int s, int e)
{
    if(s > e)
    return NULL;

    int mid = (s + e)/2;
    Node* root = new Node(sort[mid]);
    root->left = NormalBstToBalancedBst(sort, s, mid - 1);
    root->right = NormalBstToBalancedBst(sort, mid + 1, e);
    return root;
}
int main()
{
    Node *root = NULL;
    root = GiveMeData(root);
    vector<int> sort;
    InOrder(root, sort);
    root = NormalBstToBalancedBst(sort, 0, sort.size() - 1);
    // for (int i = 0; i < sort.size(); i++)
    // {
    //     cout<<sort[i]<<" ";
    // }
    // cout<<endl;
    // cout<<root->data<<endl;
    // cout<<root->left->data<<" "<<root->right->data<<endl;
    // cout<<root->left->left->data<<" "<<root->left->right->data<<" "<<root->right->left->data<<" "<<root->right->right->data<<endl;  
}
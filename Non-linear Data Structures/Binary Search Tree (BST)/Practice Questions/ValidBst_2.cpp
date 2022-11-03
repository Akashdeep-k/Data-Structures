//To check a given binary tree is a binary search tree or not using InOrder traversal
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
void InOrder(node* root, vector<int> &vals){
    if(root == NULL)
    return ;
    InOrder(root->left, vals);
    vals.push_back(root->data);
    InOrder(root->right, vals);
}
bool sorted_or_not(vector<int> vals){
    int sort = true;
    for (int i = 0; i < vals.size(); i++)
    {
        if(vals[i] > vals[i+1])
        sort = false;
    }
    return sort;
}
bool ValidBst(node* root){
    if(root == NULL)
    return true;
    vector<int> vals;
    InOrder(root, vals);
    bool valid = sorted_or_not(vals);
    return valid;
}
node* creation(node* root){
    cout<<"Enter the data (-1 if no child) : ";
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    else{
        root = new node(d);
        cout<<"Enter the data for left child of "<<d<<endl;
        root->left = creation(root);
        cout<<"Enter the data for right child of "<<d<<endl;
        root->right = creation(root);
        return root;
    }
}
int main()
{
    node *root = NULL;
    root = creation(root);
    bool val = ValidBst(root);
    cout << boolalpha << val << endl;
    return 0;
}
//To check a given binary tree is a binary search tree or not
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
bool ValidBst(node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = ValidBst(root->left, min, root->data-1);
        bool right = ValidBst(root->right, root->data+1, max);
        return left && right;
    }
    else{
        return false;
    }
}
int main()
{
    node *root = NULL;
    // make a Binary Tree and update the root
    bool val = ValidBst(root, INT_MIN, INT_MAX);
    cout << boolalpha << val << endl;
    return 0;
}
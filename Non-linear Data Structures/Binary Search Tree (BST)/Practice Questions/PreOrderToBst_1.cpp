//Time Complexity : worst case : N^2
//                  average case : N*logN
#include<iostream>
#include<vector>
using namespace std;
class node{
    public :
    int data;
    node* left; 
    node* right;
    node(){};
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node* TreeFromPre(node* root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(root->data > d)
    root->left = TreeFromPre(root->left, d);
    if(root->data < d)
    root->right = TreeFromPre(root->right, d);
    return root;
}
node* PreData(node* root, vector<int> pre){
    for (int i = 0; i < pre.size(); i++)
    {
        root = TreeFromPre(root, pre[i]);
    }
    return root;
}
void InOrder(node* root){
    if(root == NULL)
    return;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
int main(){
    //Enter elements of preorder traversal
    int d;
    cin>>d;
    vector<int> preOrder;
    while(d != -1){
        preOrder.push_back(d);
        cin>>d;
    }
    node* root = NULL;
    root = PreData(root, preOrder);
    InOrder(root);
    return 0;
}
#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* left;
    node* right;
    node(){
        this->left = NULL;
        this->right = NULL;
    }
};
node* creation(node* root){
    cout<<"Enter the data (-1 if no child) : ";
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    else{
        root = new node;
        root->data = d;
        cout<<"Enter the data for left child of "<<d<<endl;
        root->left = creation(root);
        cout<<"Enter the data for right child of "<<d<<endl;
        root->right = creation(root);
        return root;
    }
}
int main(){
    node* root = NULL;
    root = creation(root);
    return 0;
}
//not optimized for space
#include<iostream>
#include<vector>
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
node* GiveMeData(node *root)
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
void InOrder(node *root, vector<int> &sorted)
{
    if (root == NULL)
        return;

    InOrder(root->left, sorted);
    sorted.push_back(root->data);
    InOrder(root->right, sorted);
}
void InOrderWithoutStoring(node *root)
{
    if (root == NULL)
        return;

    InOrderWithoutStoring(root->left);
    cout<<root->data<<" ";
    InOrderWithoutStoring(root->right);
}
int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    cout<<"Enter data for first BST : ";
    root1 = GiveMeData(root1);
    cout<<"Enter data for second BST : ";
    root2 = GiveMeData(root2);
    vector<int> BST1;
    vector<int> BST2;
    InOrder(root1, BST1);
    InOrder(root2, BST2);
    int i = 0;
    int j = 0;
    int len1 = BST1.size();
    int len2 = BST2.size();
    vector<int> Common;
    while(i < len1 && j < len2){
        if(BST1[i] == BST2[j]){
            Common.push_back(BST1[i++]);
            j++;
        }
        else if(BST1[i] < BST2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    node* com = NULL;
    for (int i = 0; i < Common.size(); i++)
    {
        com = MakeBst(com, Common[i]);
    }
    InOrderWithoutStoring(com);
    return 0;
}
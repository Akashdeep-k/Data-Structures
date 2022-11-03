//Two Sum In BST
#include<iostream>
#include<vector>
using namespace std;
class node{
    public :
    int data;
    node* left;
    node* right;
    node(int data){
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
pair<int, int> TwoSum(node* root, int sum){
    vector<int> sorted;
    InOrder(root, sorted);

    int i = 0;
    int j = sorted.size()-1;
    while(i < j){
        if((sorted[i] + sorted[j]) == sum){
            return {sorted[i], sorted[j]};
        }
        else if((sorted[i] + sorted[j]) < sum){
            i++;
        }
        else if((sorted[i] + sorted[j]) > sum){
            j--;
        }
    }
    return {-1, -1};
}
int main(){
    node* root = NULL;
    root = GiveMeData(root);
    int key;
    cin>>key;
    pair<int, int> sum = TwoSum(root, key);
    if(sum.first != -1 && sum.second != -1)
    cout<<sum.first<<" "<<sum.second<<endl;
    else
    cout<<"No pair found"<<endl;
    return 0;
}
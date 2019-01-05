#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }



};
node* buildTree()
{

    int d;
    cout<<"Enter the Data : ";
    cin>>d;
    /// Base Case
    if(d== -1)
    {
        return NULL;
    }

    ///Rec Case
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;

}

void InorderTraversal(node* root)
{
    ///Base Case
    if(root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}
int main()
{
    node * root = NULL;
    root = buildTree();
    InorderTraversal(root);

    return 0;
}

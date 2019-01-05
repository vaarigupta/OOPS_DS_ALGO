#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node * right;

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
    cout<<"Enter the Data ";
    cin>>d;
    ///Base Case
    if(d == -1)
    {
        return NULL;
    }

    ///rec Case
    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;

}
void PostOrderTraversal(node* root)
{
    ///Base Case
    if(root == NULL)
    {
        return ;
    }
    ///Rec Case
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node * root = buildTree();
    PostOrderTraversal(root);

    return 0;
}

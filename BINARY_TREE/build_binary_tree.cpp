#include<iostream>
using namespace std;
///Preorder Traversal
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
    cout<<"Enter the data : ";
    cin>>d;
    ///base case
    if(d== -1)
    {
        return NULL;
    }

    ///rec case
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void print (node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
     print(root->left);
     print(root->right);
}
int main()
{
    node* root = NULL;
   /// cout<<"Enter the Elements : "<<endl;
    root = buildTree();
    cout<<"Your Tree : ";
    print(root);
    return 0;
}

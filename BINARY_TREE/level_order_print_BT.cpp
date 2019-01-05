#include<iostream>
#include<queue>
using namespace std;
///Level Order Printing
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

node * buildTree()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;
    ///base case
    if(d == -1)
    {
        return NULL;
    }

    ///rec case
    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;


}
void levelOrderPrint(node* root)
{
    ///stores the addresses of the root and its left and right child
   queue<node*> q;
   q.push(root);
   while(!q.empty())
   {
       node* f = q.front();
       cout<<f->data<<" ";
        q.pop();
       if(f->left)
       {
           q.push(f->left);
       }
       if(f->right)
       {
           q.push(f->right);
       }
   }
}
int main()
{
    node* root = NULL;
    root = buildTree();
    levelOrderPrint(root);

    return 0;
}

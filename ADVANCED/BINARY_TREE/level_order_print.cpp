#include<iostream>
#include<queue>
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
    cout<<"Enter the data : ";
    cin>>d;

    if(d== -1)
    {
        return NULL;
    }
    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

node* levelOrderInput()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;
    if( d == -1)
    {
        return NULL;
    }
    node * n = new node(d);
    queue<node*> q;
    q.push(n);
    while(!q.empty())
    {
        node * f = q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<" : ";
        cin>>d;

        if(d!= -1)
        {
        f->left = new node(d);
        q.push(f->left);
        }

        cout<<"Enter the right child of "<<f->data<<" : ";
        cin>>d;
        if(d!= -1)
        {
        f->right = new node(d);
        q.push(f->right);

        }

    }
    return n;
}
void printTree(node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
void Inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void PostOrder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrderPrint(node* root)
{
    queue<node*> q;
    if(root == NULL)
    {
        return ;
    }

    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
       node * f = q.front();
       q.pop();
        if(f == NULL)
        {

            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
             cout<<f->data<<" ";
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


}
int main()
{
    node* root = NULL;
    root = levelOrderInput();
    cout<<"Pre Order Traversal : "<<endl;
    printTree(root);
    cout<<endl;
     cout<<"InOrder Traversal : "<<endl;
     Inorder(root);
     cout<<endl;
    cout<<"Post Order Traversal : "<<endl;
    PostOrder(root);
    cout<<endl;
    cout<<"Level Order Print  : "<<endl;
    levelOrderPrint(root);
    cout<<endl;


    return 0;
}

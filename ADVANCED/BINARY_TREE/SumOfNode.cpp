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

int countNode(node* root)
{

    if(root == NULL)
    {
        return 0;
    }

     int leftTreeCount = countNode(root->left);
    int rightTreeCount = countNode(root->right);
    return leftTreeCount + rightTreeCount + 1;

}
int SumOfNodes(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftSum = SumOfNodes(root->left);
    int rightSum = SumOfNodes(root->right);
    return root->data + leftSum + rightSum;
}
node * buildTree()
{
    int d;
    cout<<"Enter the Data : ";
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }

    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
}

node* buildTreeByLevel()
{
    int d ;
    queue<node*> q;
    cout<<"Enter the data : ";
    cin>>d;
    if(d== -1)
    {
        return NULL;
    }
    node * n = new node(d);
    q.push(n);
    while(!q.empty())
    {
        node * parent = q.front();
        q.pop();
        int lc ,rc ;
        cout<<"Enter the Children of "<<parent->data<<" : ";
        cin>>lc>>rc;
        if(lc!= -1)
        {
            parent->left = new node(lc);
            q.push(parent->left);
        }
        if(rc!= -1)
        {
            parent->right = new node(rc);
            q.push(parent->right);
        }
    }
    return n;
}
void BFS(node * root)
{
    if(root == NULL)
    {
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node * parent = q.front();
        q.pop();
        if(parent == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<parent->data<<" ";
            if(parent->left)
            {
                q.push(parent->left);
            }
            if(parent->right)
            {
                q.push(parent->right);
            }
        }
    }



}
int main()
{
    node* root = NULL;
    root = buildTreeByLevel();
    BFS(root);
    cout<<endl;
    cout<<"TOTAL NODES : "<<countNode(root)<<endl;
    cout<<"Sum Of Nodes : "<<SumOfNodes(root)<<endl;
    return 0;
}

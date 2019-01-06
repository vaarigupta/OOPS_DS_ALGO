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
    cout<<"Enter the entry : ";
    cin>>d;
    ///base case
    if(d== -1)
    {
        return NULL;
    }
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
int heightOfTheTree(node* root)
{
    queue<node*> q;
    int cnt = 0;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
    q.push(root);
    q.push(NULL);
    cnt++;
    while(!q.empty())
    {
        node* ft = q.front();
        q.pop();
        if(ft ==NULL)
        {
            cnt++;
            if(!q.empty())
            {
                q.push(NULL);
            }

        }
        else
        {
        if(ft->left)
        {
            q.push(ft->left);
        }
        if(ft->right)
        {
            q.push(ft->right);
        }
        }
    }

    }
    return cnt-1;


}
int heightOfTheTreeRec(node* root)
{
    ///base case
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(heightOfTheTreeRec(root->left),heightOfTheTreeRec(root->right));
}
int main()
{
    node* root = NULL;
    root = buildTree();
    int height = heightOfTheTreeRec(root);
    cout<<"Height of the tree : "<<height;

    return 0;
}

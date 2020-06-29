#include<iostream>
#include<queue>
using namespace std;
///Approach using Queues
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
    ///base Case
    if(d== -1)
    {
        return NULL;
    }

    ///Rec Case
    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
int countNode(node* root)
{
    queue<node*> q;
    int cnt = 0;
    if(root ==NULL)
    {
        return 0;
    }
    q.push(root);
    cnt++;
    while(!q.empty())
    {
        node* f = q.front();
        q.pop();
        if(f->left)
        {
            q.push(f->left);
            cnt++;
        }
        if(f->right)
        {
            q.push(f->right);
            cnt++;
        }
    }
    return cnt;

}

int main()
{
    node* root = NULL;
    root = buildTree();
    int cnt = countNode(root);
    cout<<"Total Nodes "<<cnt<<endl;
    return 0;
}

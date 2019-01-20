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
node* insertNode( node*root ,int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

        if(d <= root->data )
        {
           root->left = insertNode(root->left,d);
        }
        if(d > root->data)
        {
            root->right = insertNode(root->right,d);
        }
        return root;
}
node* buildBST()
{
    int d;
    cout<<"Enter the data :";
    cin>>d;
    node* root = NULL;
    while(d!= -1)
    {
        root = insertNode(root ,d);
        cout<<"Enter the data :";
        cin>>d;
    }
    return root;
}
void printBylevel(node* root)
{
    queue<node*> q;
    if(root ==NULL)
    {
        return ;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* frontQ = q.front();
        q.pop();
        if(frontQ == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontQ->data<<" ";
            if(frontQ->left)
            {
                q.push(frontQ->left);
            }
            if(frontQ->right)
            {
                q.push(frontQ->right);
            }
        }
    }
}
int main()
{

    node * root = NULL;
    root = buildBST();
    printBylevel(root);
    return 0;
}

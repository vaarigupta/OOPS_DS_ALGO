#include<iostream>
#include<vector>
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

node* insertNodeInBST(node* root, int key)
{
    if(root==NULL)
    {
        root = new node(key);
        return root;
    }
    if(key<=root->data)
    {
        root->left = insertNodeInBST(root->left,key);
    }
    if(key>root->data)
    {
        root->right = insertNodeInBST(root->right,key);
    }
    return root;

}
node* buildBST(vector<int> arr)
{
    node* root = NULL;
    for(int i=0;i<arr.size();i++)
    {
        root = insertNodeInBST(root,arr[i]);
    }
    return root;

}

void PreOrderBSTTraversal(node* root)
{

    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrderBSTTraversal(root->left);
    PreOrderBSTTraversal(root->right);
}

void InOrderTraversal(node* root)
{
    if(root==NULL)
        return;

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}
void PostOrderTraversal(node* root)
{

    if(root==NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void LevelOrderBSTTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        if(front==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<" --";
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }

    }
}
int main()
{
    vector<int> arr = {4,3,2,1,5,6};
    node* root = buildBST(arr);
    PreOrderBSTTraversal(root);
    cout<<endl;
    InOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    LevelOrderBSTTraversal(root);

    return 0;
}

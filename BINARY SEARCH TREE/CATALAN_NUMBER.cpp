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
node* insertInBST(node* &root , int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }
    if(d<= root->data)
    {
        root->left = insertInBST(root->left , d);
    }
    if(d > root->data)
    {
        root->right = insertInBST(root->right,d);
    }
    return root;
}
node* buildBST()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;
    node* root = NULL;
    while(d!= -1)
    {
        root = insertInBST(root ,d);
         cout<<"Enter the data : ";
        cin>>d;
    }
    return root;
}

void printBylevel(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
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
int catalanNum ( int key)
{


}
int main()
{
    node* root = buildBST();
    cout<<"YOUR BST : "<<endl;
    printBylevel(root);
    return 0;
}

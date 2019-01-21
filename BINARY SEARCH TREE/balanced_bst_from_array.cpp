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

node* BSTfromArray(int *a, int s , int e)
{
    int mid;
    node* root ;
    if(s>e)
    {
        return NULL;
    }
    if(s<=e)
    {
       mid =(s+e) /2 ;
       root = new node(a[mid]);
       root->left = BSTfromArray(a, s , mid-1);
       root->right = BSTfromArray(a , mid+1,e);
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
        node* f =q.front();
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
    int a[] = {1 ,2 ,3 ,4 ,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(int);
    node* root = BSTfromArray(a,0,n-1);
    printBylevel(root);

    return 0;
}

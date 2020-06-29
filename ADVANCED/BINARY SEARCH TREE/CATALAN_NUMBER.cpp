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

///Catalan Number - Sum of f(i-1)*f(n-i)  OR 2nCn/(n+1)
int catalanNum ( int n)
{
    int ans =0;
    if(n == 0)
    {
        return 1;
    }
    for(int i =1;i<=n;i++)
    {
        ans += catalanNum(i-1)*catalanNum(n-i);
    }
return ans;

}
int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;

    }

    return n*fact(n-1);
}

int nCr(int n , int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}

int catalan(int n)
{
    int num = nCr(2*n,n);
    int den = n+1;
    return num/den;
}
int main()
{
//    node* root = buildBST();
//    cout<<"YOUR BST : "<<endl;
//    printBylevel(root);
     int n ,bst;
    cout<<"Enter the number : ";
    cin>>n;
    for(int i =0;i<=n;i++)
    {
    bst = catalanNum(i);
    cout<<"Possible number of BST's "<<bst<<endl;

    }
    return 0;
}

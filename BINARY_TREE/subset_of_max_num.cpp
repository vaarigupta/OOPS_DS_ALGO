#include<iostream>
#include<queue>
using namespace std;
class node
{

public :
    int data;
    node *left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildByLevel()
{
    int d;
    queue<node*> q;
    cout<<"Enter the value : ";
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }
    node * n = new node(d);
    q.push(n);
    while(!q.empty())
    {
        node *f = q.front();
        q.pop();
        int c1 , c2;
        cout<<"Enter the children of "<<f->data<<" : ";
        cin>>c1>>c2;
        if(c1!= -1)
        {
            node* n = new node(c1);
            f->left = n;
            q.push(f->left);
        }
        if(c2!= -1)
        {
            node * n = new node(c2);
            f->right = n;
            q.push(f->right);
        }
    }
    return n;
}
void printByLevel(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
       node* f = q.front();
       if(f == NULL)
       {
           q.pop();
           cout<<endl;
           if(!q.empty())
           {
               q.push(NULL);
           }
       }
       else
       {
           q.pop();
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
class myPair
{
public:
    int inc;
    int exc;
};

myPair maxSum(node*root)
{
    myPair p;
    if(root == NULL)
    {
       p.inc = 0;
       p.exc = 0;
       return p;
    }

    myPair left = maxSum(root->left);
    myPair right = maxSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc , left.exc) + max(right.inc , right.exc);

     return p;


}
int main()
{
   node *root = NULL;
   root = buildByLevel();
   cout<<"Your Tree : "<<endl;
   printByLevel(root);
   cout<<endl;
   myPair p =maxSum(root);
   int maxSubset = max(p.inc , p.exc);
   cout<<"Maximum Sum of a subset "<<maxSubset;
    return 0;
}

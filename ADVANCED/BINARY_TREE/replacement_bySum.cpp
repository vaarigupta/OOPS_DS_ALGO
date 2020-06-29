#include<iostream>
#include<queue>
using namespace std;
class node
{

    public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left= NULL;
        right= NULL;
    }

};

node* buildByLevel()
{
    int d;
    queue<node*> q;
    cout<<"Enter the data :";
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }
    node *n = new node(d);
    q.push(n);

    while(!q.empty())
    {
        node * p = q.front();
        q.pop();
        int lc , rc;
        cout<<"Enter the children Of "<<p->data<<" : ";
        cin>>lc>>rc;
        if(lc!= -1)
        {
            p->left = new node(lc);
            q.push(p->left);
        }
        if(rc!= -1)
        {
            p->right = new node(rc);
            q.push(p->right);
        }
    }
    return n;
}
void printByLevel(node * root)
{
    queue<node*> q;
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
int SumOfNodes(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
   int s1 = SumOfNodes(root->left);
   int s2 = SumOfNodes(root->right);
   return root->data + s1 +s2;
}
node* replaceBySum(node* &root)
{
    if(root == NULL)
    {
        return ;
    }
    ///node * lt = replaceBySum(root->left);
    ///node * rt = replaceBySum(root->right);
    else{
         root->data = SumOfNodes(root->left) + SumOfNodes(root->right);

    }



}
int main()
{
    node * tree = buildByLevel();
    printByLevel(tree);
    return 0;
}

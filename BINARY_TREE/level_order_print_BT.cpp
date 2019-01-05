#include<iostream>
#include<queue>
using namespace std;
///Level Order Printing
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

node * buildTree()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;
    ///base case
    if(d == -1)
    {
        return NULL;
    }

    ///rec case
    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;


}
   ///Use of queue is to make sure that the level that comes first should come out first
   ///And in Queue , the ordering is like that first In first Out
   /// 5        -> 1st Level
/// 6   8        -> 2nd Level
///7   9  10     -> 3rd Level

void levelOrderPrint(node* root)
{
    ///stores the addresses of the root and its left and right child
   queue<node*> q;
   q.push(root);

   while(!q.empty())
   {
       node* f = q.front();
       cout<<f->data<<" ";
        q.pop();
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
void levelOrderPrint2(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        q.pop();
        if(f==NULL)
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
    node* root = NULL;
    root = buildTree();
    levelOrderPrint2(root);

    return 0;
}

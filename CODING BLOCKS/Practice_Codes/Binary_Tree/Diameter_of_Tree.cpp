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

node* buildTree(node* root)
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }
    root = new node(d);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
///Pre Order Print
void PreOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";///root
    PreOrderPrint(root->left);///left
    PreOrderPrint(root->right);///right
}
///In Order Print
void InOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrderPrint(root->left);
    cout<<root->data<<" ";
    InOrderPrint(root->right);
}
///Post Order Print
void PostOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }

    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    cout<<root->data<<" ";
}
void levelOrderPrint(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *f = q.front();
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
        if(f->left )
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
int height(node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
int countNode(node * root)
{
    if(root ==NULL)
    {
        return 0;
    }
    int l = countNode(root->left);
    int r = countNode(root->right);
    return 1+ l+r;
}
int SumOfNodes(node * root)
{

    if(root ==NULL)
    {
        return 0;
    }
    int l = SumOfNodes(root->left);
    int r = SumOfNodes(root->right);
    return root->data + l + r;

}
int diameter(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);
    int totalH = height(root->left) + height(root->right)+1;

    return max(max(leftD,rightD),totalH);
}

int main()
{

    node* root = NULL;
    root = buildTree(root);
    cout<<"Level order Print :"<<endl;
    levelOrderPrint(root);
    cout<<endl<<"Height of tree : "<<height(root)<<endl;
     cout<<endl<<"Total nodes in tree : "<<countNode(root)<<endl;
     cout<<endl<<"Sum of  nodes in tree : "<<SumOfNodes(root)<<endl;
      cout<<endl<<"Diameter of tree : "<<diameter(root)<<endl;
    return 0;
}

/*

right Skew tree
8 -1 3 -1 4 -1 6 -1 7 -1 -1
Level order Print :
8
3
4
6
7

Height of tree : 5

Total nodes in tree : 5

Sum of  nodes in tree : 28

Diameter of tree : 5

-----------------------------------

Binary tree
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Level order Print :
8
10 3
1 6 14
9 7 13

Height of tree : 4

Total nodes in tree : 9

Sum of  nodes in tree : 71
*/






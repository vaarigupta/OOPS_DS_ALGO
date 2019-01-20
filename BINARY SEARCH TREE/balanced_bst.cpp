#include<iostream>
#include<queue>
#include<cmath>
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
node* insertInBST(node*&root , int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }
    if(d <= root->data)
    {
       root->left = insertInBST(root->left , d);
    }
    if(d > root->data)
    {
        root->right = insertInBST(root->right, d);
    }
    return root;
}
node* buildBST()
{
    int d;
    cout<<"Enter the data :";
    cin>>d;
    node* root= NULL;
    while(d!= -1)
    {
        root = insertInBST(root , d);
        cout<<"Enter the data : ";
        cin>>d;
    }
    return root;
}
void printBylevel(node* root)
{
    queue<node*> q;
    if(root == NULL)
    {
        return;
    }
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
int height(node* root)
{
    if(root ==NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);
}
/// complexity - O(n2)
bool balancedTree(node* root)
{
    if(root == NULL)
    {
        return true;
    }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int h ;
        if(h1>h2)
        {
            h = h1- h2;
        }
        else
        {
            h = h2 - h1;
        }
        if(h== 1 || h ==0)
        {
            balancedTree(root->left);
            balancedTree(root->right);
            return true;
        }
        if(h > 1)
        {
            return false;
        }
}
class myPair
{

public:
    int height;
    bool balanced;
};
///complexity - O(n)
myPair fastbalancedTree(node* root)
{
    myPair p;
    if(root == NULL)
    {
       p.height = 0;
       p.balanced = true;
       return p;
    }
    myPair leftTree = fastbalancedTree(root->left);
    myPair rightTree = fastbalancedTree(root->right);
    int h = abs(leftTree.height -rightTree.height);
    if( h<= 1 && leftTree.balanced && rightTree.balanced)
    {
        p.balanced = true;
    }
    else
    {
        p.balanced = false;
    }
    p.height = 1 + max(leftTree.height , rightTree.height);
    return p;


}
istream& operator>>(istream &is , node* &root)
{
    root = buildBST();
    return is;
}
ostream & operator<<(ostream &os , node* root)
{
    printBylevel(root);
    return os;
}
int main()
{
    node* root = NULL;
    cin>>root;
    cout<<"YOUR BINARY SEARCH TREE : "<<endl<<root<<endl;
//    if(balancedTree(root))
//    {
//        cout<<"yes balanced BST";
//    }
//    else
//    {
//        cout<<"NO , it is not balanced ";
//    }
    myPair p = fastbalancedTree(root);
    if(p.balanced)
    {
        cout<<"yes balanced BST";
    }
     else
    {
        cout<<"NO , it is not balanced ";
    }

    return 0;
}

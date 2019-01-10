#include<iostream>
using namespace std;
///Time Complexity - O(n^2)
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
    cout<<"Enter the value : ";
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }

    node * n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int LST = height(root->left);
    int RST = height(root->right);
    return 1 + max(LST , RST);
}
void printKthLevel(node * root , int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k ==1)
    {
        cout<<root->data<<" ";
        return;
    }

    printKthLevel(root->left , k-1);
    printKthLevel(root->right , k-1);

}

void printAllLevel(node* root)
{
    int h = height(root);
    for(int i = 1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
}
int main()
{
    node* root = buildTree();
    printKthLevel(root , 3);
    cout<<endl;
    printAllLevel(root);
    return 0;
}

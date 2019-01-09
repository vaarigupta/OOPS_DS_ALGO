#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node * right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* buildTree()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;
    if(d== -1)
    {
        return NULL;
    }
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void print(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int height(node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
int diameter(node* root)
{
    if(root ==NULL)
    {
        return 0;
    }

    int hmax =  max(diameter(root->left),diameter(root->right));
    int hmin =  min(diameter(root->left),diameter(root->right));
    return 1+ hmax + hmin ;

}
int diameterCorrect(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameterCorrect(root->left);
    int op3 = diameterCorrect(root->right);

    return max(op1,max( op2, op3));


}
int main()
{
    node* root = NULL;
    root = buildTree();
    print(root);
    cout<<endl;
    cout<<"Diameter "<<diameterCorrect(root)<<endl;
    return 0;
}


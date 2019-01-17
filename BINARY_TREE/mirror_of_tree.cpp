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
node* buildByLevel()
{
    int d;
    queue<node*> q;
    cout<<"Enter the data : ";
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }
    node* root = new node(d);
    q.push(root);

    while(!q.empty())
    {
        node* parent = q.front();
        q.pop();
        int c1 , c2;
        cout<<"Enter the children of "<<parent->data<<" : ";
        cin>>c1>>c2;
        if(c1!= -1)
        {
             parent->left = new node(c1);
              q.push(parent->left);
        }
        if(c2 != -1)
        {
            parent->right = new node(c2);
            q.push(parent->right);
        }

    }
    return root;

}

void printByLevel(node* root)
{
    queue<node*> q;
    if(root== NULL)
    {
        return ;
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
/// We can pass root either by reference or data as we are not changing the address
///we are only altering the data in the root
void mirrorImage(node *root)
{
    if(root == NULL)
    {
        return;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
}
int main()
{

    node* root = buildByLevel();
    cout<<"Your Tree : "<<endl;
    printByLevel(root);
    cout<<endl;
    mirrorImage(root);
    printByLevel(root);
    return 0;
}

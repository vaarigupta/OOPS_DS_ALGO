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
    if(d <= root->data)
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
    cout<<"Enter the data :";
    cin>>d;
    node* root = NULL;
    while(d!= -1)
    {
        root = insertInBST(root , d);
        cout<<"Enter the data :";
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
int minNode(node* root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;
}
int maxNode(node* root)
{
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;
}
node* deletion (node* &root , int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        ///Cases - 0 child , 1 child , 2 children

        ///0 Child
        if(root->left == NULL && root->right== NULL)
        {
            delete root;
            return NULL;
        }
        /// 1 child
        else if(root->left== NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;

        }
        else if(root->left!=NULL && root->right== NULL)
        {
            node* temp  = root->left;
            delete root;
            return temp;
        }

        ///2 children
        else
        {
            int replacement = minNode(root->right);
            root->data = replacement;
            root->right =  deletion(root->right,root->data);
            return root;
        }
    }
    if(key < root->data )
    {
        root->left = deletion(root->left , key);
        return root;


    }
    if( key > root->data)
    {
        root->right = deletion(root->right,key);
        return root;
    }

}
node* deletion1(node* &root , int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        ///Cases - 0 child , 1 child , 2 children

        ///0 Child
        if(root->left == NULL && root->right== NULL)
        {
            delete root;
            return NULL;
        }
        /// 1 child
        else if(root->left== NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;

        }
        else if(root->left!=NULL && root->right== NULL)
        {
            node* temp  = root->left;
            delete root;
            return temp;
        }

        ///2 children
        else
        {
            int replacement = maxNode(root->left);
            root->data = replacement;
            root->left =  deletion(root->left,root->data);
            return root;
        }
    }
    if(key < root->data )
    {
        root->left = deletion(root->left , key);
        return root;


    }
    if( key > root->data)
    {
        root->right = deletion(root->right,key);
        return root;
    }

}
int main()
{
    node * root = buildBST();
    cout<<"Your BST "<<endl;
    printBylevel(root);
    int key;
    cout<<"Enter the key to be deleted : ";
    cin>>key;
    while(key!= -1)
    {
        deletion1(root,key);
        printBylevel(root);
        cout<<"Enter the key to be deleted : ";
        cin>>key;
    }

    return 0;
}

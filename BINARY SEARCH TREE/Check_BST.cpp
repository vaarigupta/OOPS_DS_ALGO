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

///Insert Node in BST
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

///Build Binary Tree
node* buildBinaryTree()
{
    int d;
    cout<<"Enter the data : ";
    cin>>d;

    if(d == -1)
    {
        return NULL;
    }

    node * root = new node(d);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;
}

///Build Binary Search Tree
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

///Print by level
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

node* buildBSTfromArr(int *a,int s , int e)
{
    int mid;
    node* root;
    if(s>e)
    {
        return NULL;
    }
    if(s<=e)
    {
         mid = (s+e)/2;
        root = new node(a[mid]);
        root->left = buildBSTfromArr(a,s,mid-1);
        root->right = buildBSTfromArr(a,mid+1,e);

    }
    return root;

}

///Mine Logic - to check given tree is a BST
bool checkBSTtry(node* root)
{
  bool ans1 , ans2;
  if(root == NULL)
  {
      return true;
  }
     if(root->left->data <= root->data)
     {
          ans1 = checkBSTtry(root->left);
          return ans1;

     }
     if(root->right->data > root->data)
     {
         ans2 = checkBSTtry(root->right);
         return ans2;
     }
     if(ans1 && ans2)
     {
         return true;
     }
     else
     {
         return false;
     }


}


bool checkBST(node* root , int minValue = INT_MIN , int maxValue = INT_MAX)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data >= minValue && root->data < maxValue && checkBST(root->left,minValue , root->data) && checkBST(root->right,root->data , maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minimum (node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    while(root->left!= NULL)
    {
        root = root->left;
    }
    return root->data;
}
int maximum (node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    while(root->right!= NULL)
    {
        root = root->right;
    }
    return root->data;
}

bool checkBST2(node* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data >= maximum(root->left) && root->data < minimum(root->right) && checkBST2(root->left) && checkBST2(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    int a[] = { 1,2,3,4,5,6,7,8};
    int n = sizeof(a)/sizeof(int);
    node* root = buildBSTfromArr(a,0,n-1);
    cout<<"YOUR BST : "<<endl;
    printBylevel(root);
    if(checkBST2(root))
    {
        cout<<"Yes it is a BST ";
    }
    else
    {
        cout<<"No it is not a BST ";
    }
    return 0;
}


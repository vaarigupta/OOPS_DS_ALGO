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
//node* insertInBST(node*&root , int d)
//{
//    if(root == NULL)
//    {
//        root = new node(d);
//        return root;
//    }
//    if(d <= root->data)
//    {
//        root->left = insertInBST(root->left,d);
//    }
//    if(d > root->data)
//    {
//        root->right = insertInBST(root->right , d);
//    }
//    return root;
//}
//node* buildBST()
//{
//    int d;
//    cout<<"Enter the data : ";
//    cin>>d;
//    node* root = NULL;
//    while(d!= -1)
//    {
//        root = insertInBST(root , d);
//        cout<<"Enter the data : ";
//        cin>>d;
//    }
//    return root;
//}

node* BSTfromArray(int *a, int s , int e)
{
    int mid;
    node* root ;
    if(s>e)
    {
        return NULL;
    }
    if(s<=e)
    {
       mid =(s+e) /2 ;
       root = new node(a[mid]);
       root->left = BSTfromArray(a, s , mid-1);
       root->right = BSTfromArray(a , mid+1,e);
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
node* minNode(node* root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

node* maxNode(node* root)
{
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}


class LinkedList
{
public:
    node* head;
    node* tail;
};

LinkedList BSTtoLL(node* root)
{

    LinkedList l;
    if(root == NULL)
    {
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    else if(root->left == NULL && root->right ==NULL)
    {
        l.tail = root;
        l.head = root;
        return l;
    }

    else if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftTree = BSTtoLL(root->left);
        leftTree.tail->right = root;

        l.head = leftTree.head;
        l.tail = root;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightTree = BSTtoLL(root->right);
        root->right = rightTree.head;

        l.head = root;
        l.tail = rightTree.tail;
    }

    else
    {
        LinkedList leftTree = BSTtoLL(root->left);
        LinkedList rightTree = BSTtoLL(root->right);

        leftTree.tail->right = root;
        root->right = rightTree.head;

        l.head = leftTree.head;
        l.tail = rightTree.tail;
    }
    return l;
}
int main()
{
    int a[] = {1 ,2 ,4 ,5,6,8,9};
    int n = sizeof(a)/sizeof(int);
    node* root = BSTfromArray(a,0,n-1);
    printBylevel(root);

    LinkedList l = BSTtoLL(root);
    node* h = l.head;
    while(h!=NULL)
    {
        cout<<h->data<<"=>";
        h = h->right;
    }
    return 0;
}

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
node* insertNode( node*root ,int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

        if(d <= root->data )
        {
           root->left = insertNode(root->left,d);
        }
        if(d > root->data)
        {
            root->right = insertNode(root->right,d);
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
        root = insertNode(root ,d);
        cout<<"Enter the data :";
        cin>>d;
    }
    return root;
}
void printBylevel(node* root)
{
    queue<node*> q;
    if(root ==NULL)
    {
        return ;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* frontQ = q.front();
        q.pop();
        if(frontQ == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontQ->data<<" ";
            if(frontQ->left)
            {
                q.push(frontQ->left);
            }
            if(frontQ->right)
            {
                q.push(frontQ->right);
            }
        }
    }
}

///Complexity - O(height of the tree)
///O(logN)(balanced tree) <= O(H)(general) < O(N) -(skew tree)
bool searchInBST(node* root , int key)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == key)
    {
        return true;
    }
    if(key <= root->data)
    {
        return searchInBST(root->left,key);
    }
    if(key > root->data)
    {
        return searchInBST(root->right,key);
    }


}
istream& operator>>(istream &is , node*&root)
{
    root = buildBST();
    return is;

}
ostream& operator<<(ostream &os , node* root)
{
    printBylevel(root);
    return os;
}
int main()
{

    node * root = NULL;
    cin>>root;
    cout<<root;
    int key ;
    cout<<"Enter the value to be searched :";
    cin>>key;
    if(searchInBST(root , key))
    {
        cout<<"Yes "<<key<<" is in BST"<<endl;
    }
    else
    {
        cout<<"Sorry , your key is not in BST "<<endl;
    }
    return 0;
}

#include<iostream>
#include<queue>
using namespace std;
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* BuildTree(Node* root)
{
	int d;
	cin>>d;

	if(d==-1)
	{
		return NULL;
	}
	root = new Node(d);
	root->left = BuildTree(root->left);
	root->right = BuildTree(root->right);
	return root;


}
void PreOrderTraversal(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);

}
void PostOrderTraversal(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
void InOrderTraversal(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	InOrderTraversal(root->left);
	cout<<root->data<<" ";
    InOrderTraversal(root->right);
}
void LevelOrderTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* f = q.front();
		q.pop();
		if(f==NULL)
		{
			cout<<endl;
			if(!q.empty()) q.push(NULL);

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
int CountNodes(Node* root)
{
if(root==NULL) return 0;

int left = CountNodes(root->left);
int right = CountNodes(root->right);

return left+ right+1;

}
int SumOfNodes(Node* root)
{
if(root==NULL) return 0;

int left = SumOfNodes(root->left);
int right = SumOfNodes(root->right);

return left+ right+ root->data;

}

int main()
{
	Node* root = NULL;
    root = BuildTree(root);
    PreOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    InOrderTraversal(root);
    cout<<endl;
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<"No. of Nodes : "<<CountNodes(root)<<endl;
     cout<<"Sum of Nodes : "<<SumOfNodes(root)<<endl;
	return 0;
}



/*

1 2 4 -1 -1 5 -1 -1 3 -1 -1
1 2 4 5 3
4 5 2 3 1
4 2 5 1 3


8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13
1 9 7 6 10 13 14 3 8
1 10 9 6 7 8 3 13 14
8
10 3
1 6 14
9 7 13


*/

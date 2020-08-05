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
node* buildtree(node* &root)
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}
	root = new node(d);
	root->left = buildtree(root->left);
	root->right = buildtree(root->right);
	return root;
}
void preOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}
void postOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* curr = q.front();
		cout<<curr->data<<" ";
		q.pop();
		if(curr->left)
		{
			q.push(curr->left);
		}
		if(curr->right)
		{
			q.push(curr->right);
		}
	}
}

int main()
{
	node* root = NULL;
	root = buildtree(root);
	cout<<"Pre order "<<endl;
	preOrder(root);
	cout<<endl<<"In order "<<endl;
	inOrder(root);
	cout<<endl<<"Post order "<<endl;
	postOrder(root);
	cout<<endl<<"Level order "<<endl;
	levelOrder(root);

	return 0;


}


/*
5 6 -1 2 -1 -1 7 3 -1 -1 1 -1 -1

5 6 -1 2 -1 -1 7 3 -1 -1 1 -1 -1
Pre order
5 6 2 7 3 1
In order
6 2 5 3 7 1
Post order
2 6 3 1 7 5
Level order
5 6 7 2 3 1
*/

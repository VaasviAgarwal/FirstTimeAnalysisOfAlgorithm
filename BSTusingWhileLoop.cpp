#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
	public:
	Node *root;
	BinarySearchTree()
	{
		root=NULL;
	}
	void insert(int val);
	void inorder(Node *r);
	void preorder(Node *r);
	void postorder(Node *r);
};

void BinarySearchTree::insert(int val)
{
	Node *NewNode = new Node(val);
	if(root == NULL)
	{
		root = NewNode;
		return;
	}
	Node *r = root;
	Node *temp;
	while(true)
	{
		temp = r;
		if(r->data > val
		)
		{
			r = r->left;
			if(r==NULL)
			{
				temp->left = NewNode;
				break;
			}
		}
		else if(r->data < val)
		{
			r = r->right;
			if(r==NULL)
			{
				temp->right = NewNode;
				break;
			}
		}
	}
}

void BinarySearchTree::inorder(Node *r)
{
	if(r==NULL)
	{
		return;
	}
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);
}

void BinarySearchTree::preorder(Node *r)
{
	if(r==NULL)
	{
		return;
	}
	cout<<r->data<<" ";
	preorder(r->left);
	preorder(r->right);
}

void BinarySearchTree::postorder(Node *r)
{
	if(r==NULL)
	{
		return;
	}
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";
}

int main()
{
	BinarySearchTree bst;
	int choice;
	int val;
	do
	{
		cout<<endl;
		cout<<endl;
		cout<<"Enter 1 to insert node"<<endl;
		cout<<"Enter 2 for inorder traversal"<<endl;
		cout<<"Enter 3 for preorder traversal"<<endl;
		cout<<"Enter 4 for postorder"<<endl;
		cout<<"Enter 0 to End"<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"Enter your value : ";
			cin>>val;
			bst.insert(val);
			break;
			case 2:
			cout<<"Inorder Traversal : "<<endl;
			bst.inorder(bst.root);
			break;
			case 3:
			cout<<"Preorder Traversal : "<<endl;
			bst.preorder(bst.root);
			break;
			case 4:
			cout<<"Postorder Traversal : "<<endl;
			bst.postorder(bst.root);
			break;
			case 0:
			cout<<"Program terminated"<<endl;
			break;
			default:
			cout<<"Invalid Choice"<<endl;
		}
	}
	while(choice!=0);
	return 0;
	
}
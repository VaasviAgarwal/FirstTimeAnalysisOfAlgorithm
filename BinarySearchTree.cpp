#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left,*right;
	Node(int d)
	{
		data=d;
		left = right =NULL;
	}
};

Node *insertbst(Node*root,int val)
{
	if(root==NULL)
	{
		return new Node(val);
	}
	if(val < root->data)
	{
		root->left=insertbst(root->left,val);
	}
	else
	{
		root->right=insertbst(root->right,val);
	}
	return root;
}

// Preorder traversal   Root->left->right
void pre( Node* root) {  
  if (root == NULL)
  {
    return;
   }
  cout << root->data << " ";
  pre(root->left);
  pre(root->right);
}

// Postorder traversal left->right->root
void post( Node* root) {
  if (root == NULL)
  {
    return;
  }
  post(root->left);
  post(root->right);
  cout << root->data << " ";
}

// Inorder traversal  left->root->right
void in( Node* root) {
  if(root == NULL)
  {
    return;
  }
  in(root->left);
  cout << root->data << " ";
  in(root->right);
}

int main() {
	Node *root=NULL;
	int n;
	cout<<"Enter the number of element to insert in bst : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	root=insertbst(root,a[0]);
	for(int i=1;i<n;i++)
	{
		insertbst(root,a[i]);
	}

	do
	{
		cout<<"\n----------Menu Options-------------"<<endl;
		cout<<"1.Print Preorder\n";
		cout<<"2.Print Postorder\n";
		cout<<"3.Print Inorder\n";
		cout<<"4.Exit the menu\n";
		cout<<"Enter the desired choice\n"<<endl;
		
		cin>>n;
		switch(n)
		{
			case 1:
			cout << "Preorder traversal :  "<<endl;
  			pre(root);
			break;
			
			case 2:
			cout << "Postorder traversal : "<<endl;
  			post(root);
			break;

			case 3:
			cout << "Inorder traversal : "<<endl;
  			in(root);
			break;

			case 4:
			exit(1);
			break;
			
			default:
			cout<<"Enter the correct choice";
		}
	}while(n!=4);
	
return 0;
}
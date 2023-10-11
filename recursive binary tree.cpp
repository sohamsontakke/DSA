#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
void preorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
	cout<<endl;
}
void postorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<endl;
}
void inorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	inorder(temp->left);
	cout<<temp->data;
	inorder(temp->right);
	cout<<endl;
}
struct node *InsertNode()
{
	int n;
	cout<<"Enter data : ";
	cin>>n;
	struct node *ptr=new node();
	ptr->data=n;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
int main()
{
	root=InsertNode();
	root->left=InsertNode();
	root->left->left=InsertNode();
	root->left->right=InsertNode();
	root->right=InsertNode();
	root->right->right=InsertNode();
	cout<<"Preorder is : ";
	preorder(root);
	cout<<"Postorder is : ";
	postorder(root);
	cout<<"Inorder is : ";
	inorder(root);
	return 0;
}

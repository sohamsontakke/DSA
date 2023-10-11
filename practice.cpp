#include<iostream>
#include<stdlib.h>
using namespace std;
struct BST
{
	struct BST *left;
	int data;
	struct BST *right;
};
struct BST *root=NULL;
struct BST *create_node(int data)
{
	struct BST *new_node=new BST;
	new_node->data=data;
	new_node->left=new_node->right=NULL;
	return new_node;
}
struct BST *insert(struct BST *root, int data)
{
	if (root==NULL)
	{
		root=create_node(data);
		return root;
	}
	else
	{
		if (data <= root->data)
		{
			root->left=insert(root->left,data);
		}
		else
		{
			root->right=insert(root->right,data);
		}
		return root;
	}
}
void inorder(struct BST *node)
{
	if (node==NULL)
	{
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);	
}
void preorder (struct BST *node)
{
	if (node==NULL)
	{
		return;
	}
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}
void postorder (struct BST *node)
{
	if (node==NULL)
	{
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
}
int height(struct BST *root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		if(height(root->right)>(height(root->left)))
		{
			return (1+height(root->right));
		}
		else
		{
			return (1+height(root->left));
		}
	}
}
int findmin(struct BST *root)
{
	if (root==NULL)
	{
		cout<<"Tree is empty!!";
		return -1;
	}
	struct BST *current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current->data;
}
void search (struct BST *root ,int key)
{
	if (root==NULL)
	{
		cout<<"Key not found!!";
		return;
	}
	else
	{
		if (root->data==key)
		{
			cout<<"Key found"<<endl;
		}
		else if (key < root->data)
		{
			search (root->left,key);
		}
		else
		{
			search (root->right,key);
		}
	}
}
int main()
{
	int ch,data,key;
	while (ch!=8)
	{
	 cout << "\n***********************" << endl; 
	 cout << "Operations on BST" << endl; 
	 cout << "1. Insert Element." << endl; 
	 cout << "2. No.of nodes in longest path of the tree." << endl; 
	 cout << "3. Smallest value in the tree." << endl; 
	 cout << "4. Display." << endl; 
	 cout << "5. Mirror image of the tree." << endl; 
	 cout << "6. Search an element." << endl; 
	 cout << "7. Exit." << endl; 
	 cout << "Enter your choice : " << endl; 
	 cin >> ch; 
 	switch (ch)
 	{
 		case 1 :
 			cout<<"Enter data to insert :";
 			cin>>data;
 			root=insert(root,data);
 			break;
 		case 2:
		 	cout<<"Height of the tree is : "<<height(root);
			 break;
		case 3:
			cout<<"smallest node in the tree is : "<<findmin(root)	 ;	
 			break;
 		case 4:
		 	cout<<"Inorder"<<endl;
			 inorder(root);
			 cout<<"preorder"<<endl;
			 preorder(root);
			 cout<<"postorder"<<endl;
			 postorder(root);
			 break;
		case 5:
			cout<<"Enter key to search : ";
			cin>>key;
			search(root,key);
			break;
				 	
	 }
	}
	return 0;
}

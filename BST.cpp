#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
struct node *InsertNode(struct node *root,int n)
{
	if (root==NULL)
	{
		struct node *ptr=new node();
		ptr->data=n;
		ptr->left=ptr->right=NULL;
		root=ptr;
	}
	else if (n< root->data)
	{
		root->left=InsertNode(root->left,n);
	}
	else if (n> root->data)
	{
		root->right=InsertNode(root->right,n);
	}
	else
	{
		cout<<"Already existed : ";
		return NULL;
	}
	return root;
}
void preorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
void inorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
void postorder(struct node *temp)
{
	if (temp==NULL)
	{
		return;
	}
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}
void max()
{
	struct node *temp=root;
	while (temp->right!=NULL)
	{
		temp=temp->right;
	}
	cout<<"Maximum node is : "<<temp->data<<endl;
}
struct node *max_rec (struct node *root)
{
	if (root==NULL)
	{
		cout<<"Tree is empty "<<endl;
		return NULL;
	}
	else if (root->right)
	{
		root=max_rec(root->right);
	}
	else
	{
		return root;
	}
}
struct node *min_rec (struct node *root)
{
	if (root==NULL)
	{
		cout<<"Tree is empty "<<endl;
		return NULL;
	}
	else if (root->left)
	{
		root=min_rec(root->left);
	}
	else
	{
		return root;
	}
}
struct node *search(struct node *root,int k)
{
	if (root==NULL)
	{
		cout<<k<<" not found !!!"<<endl;
		return NULL;
	}
	else if (k<root->data)
	{
		root=search(root->left,k);
	}
	else if (k> root->data)
	{
		root=search(root->right,k);
	}
	else
	{
		return root;
	}
}
void min()
{
	struct node *temp=root;
	while (temp->left!=NULL)
	{
		temp=temp->left;
	}
	cout<<"Minimum node is : "<<temp->data<<endl;
}
int count (struct node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		int x=count(root->left);
		int y=count(root->right);
		return 1+x+y;
	}
}
int height(struct node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		int x=height(root->left);
		int y=height(root->right);
		if (x>y)
		{
			return 1+x;
		}
		else
		{
			return 1+y;
		}
	}
}
struct node *DeleteNode(struct node *root,int a)
{
	if (root==NULL)
	{
		cout<<"Tree is empty";
		return NULL;
	}
	else if (a < root->data)
	{
		root->left=DeleteNode(root->left,a);
	}
	else if (a > root->data)
	{
		root->right=DeleteNode(root->right,a);
	}
	else
	{
		struct node *temp;
		if (root->left && root->right)
		{
			temp=min_rec(root->right);
			root->data=temp->data;
			root->right=DeleteNode(root->right,temp->data);
		}
		else if (root->left)
		{
			temp=root;
			root=root->left;
			delete(temp);
		}
		else if(root->right)
		{
			temp=root;
			root=root->right;
			delete(temp);
		}
		else
		{
			root=NULL;
			return root;
		}
	}
	return root;
}
int main()
{
	int ch,k,cnt,c;
	struct node *out;
	while (1)
	{
	cout<<"\n****Menu*****"<<endl;
	cout<<"1.Insert node"<<endl;
	cout<<"2.Preorder for given nodes "<<endl;
	cout<<"3.Postorder for given nodes "<<endl;
	cout<<"4.Inorder for given nodes "<<endl;
	cout<<"5.Highest node in the bst"<<endl;
	cout<<"6.Highest node in the bst using recurssion"<<endl;
	cout<<"7.smallest node in the bst"<<endl;
	cout<<"8.smallest node in the bst using recurssion"<<endl;
	cout<<"9.Search node in the bst"<<endl;
	cout<<"10.No of nodes in BST"<<endl;
	cout<<"11.Height of BST"<<endl;
	cout<<"12.Delete any node from BST"<<endl;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch (ch)
	{
		case 1:
			int data;
			cout<<"Enter data: ";
			cin>>data;
			root=InsertNode(root,data);
			break;
			
		case 2:
			cout<<"Preorder: ";
			preorder(root);
			break;
			
		case 3:
			cout<<"Postorder: ";
			postorder(root);
			break;
			
		case 4:
			cout<<"Inorder : ";
			inorder(root);
			break;	
			
		case 5:
			max();
			break;	
		
		case 6:
			out=max_rec(root);
			if (out!=NULL)
			{
				cout<<"Max node is "<<out->data<<endl;
			}	
			break;
			
		case 7:
			min();
			break;	
			
		case 8:
			out=min_rec(root);
			if (out!=NULL)
			{
				cout<<"Min node is "<<out->data<<endl;
			}	
			break;	
			
		case 9:
			cout<<"Enter the node want to search : ";
			cin>>k;
			out=search(root,k);
			if(out!=NULL)
			{
				cout<<k<<" is present";
			}
			break;
			
		case 10:
			cnt=count(root);
			cout<<"No of nodes in BST are : "<<cnt;
			break;
			
		case 11:
			c=height(root);
			cout<<"Height of the BST is : "<<c-1;
			break;	
			
		case 12:
			int a;
			cout<<"Enter data you want to delete : ";
			cin>>a;
			
			out=search(root,a);
			if(out!=NULL)
			{
				DeleteNode(root,a);
				cout<<a<<" is deleted";
			}
			break;	
	}
	}
	return 0;
}

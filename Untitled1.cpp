#include<iostream>
using namespace std;
struct node
{
	int type;
	int id;
	struct node *next,*pre;
};
struct node *head;
void insert()
{
	struct node *temp=new node;
	cout<<"Enter patient type : ";
	cin>>temp->type;
	cout<<"Enter patiend id : ";
	cin>>temp->id;
	temp->next=NULL;
	if (head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *ptr=head;
		while(ptr->type <= temp->type && ptr->next !=NULL)
		{
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void display()
{
	struct node *temp;
	temp=head;
	while (temp->next !=NULL)
	{
		cout<<temp->type<<"  "<<temp->id<<endl;
		temp=temp->next;
	}
}
int main()
{
	int ch;
	while (ch!=3)
	{
	cout<<"****Menu****"<<endl;
	cout<<"1.Insert data"<<endl;
	cout<<"2.Display data"<<endl<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	switch (ch)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;	
	}
}
return 0;
}

#include<iostream>
#define maxSize 10
using namespace std;
int arr[maxSize+1];
int f=-1,r=-1;
void sort()
{
	for (int i=f;i<=r;i++)
	{
		for (int j=i+1;j<=r;j++)
		{
			if (arr[j] > arr[i])
			{
				int t=arr[j];
				arr[j]=arr[i];
				arr[i]=t;
			}
		}
	}
}
void enqueue()
{
	
	if (r==maxSize)
	{
		cout<<"Queue is full !!";
	}
	else
	{
		int n;
		cout<<"Enter data to insert : ";
		cin>>n;
		
		if(f==-1||r==-1)
		{
			arr[++f]=n;
			r++;
		}
		else
		{
			arr[++r]=n;
			sort();
		}
		
	}
	cout<<"Data added successfully!!";
}
void dequeue()
{
	if (r==-1)
	{
		cout<<"Queue is empty : ";
	}
	else
	{
		if(r==f)
		{
			arr[f]=0;
			f=r=-1;
		}
		else
		{
			arr[f]=0;
			f++;
		}
	}
	cout<<"Data is deleted!!";
}
void display()
{
	for(int i=0;i<=maxSize;i++)
	{
		cout<<arr[i]<<"|";
	}
}
void isfull()
{
	if (r==maxSize)
	{
		cout<<"Queue is full !!";
	}
	else
	{
		cout<<"Queue has some empty spaces!!";
	}
}
void isempty()
{
	if (r==-1)
	{
		cout<<"Queue is empty!!!";
	}
	else
	{
		cout<<"Queue contains elements!!!";
	}
}
int main()
{
	int ch;
	do
	{
	cout<<"\n****Menu****"<<endl;
	cout<<"1.Insert data in the Queue"<<endl;
	cout<<"2.Delete Data from the Queue"<<endl;
	cout<<"3.Display Queue"<<endl;
	cout<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	switch (ch)
	{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;		
	}
}while (ch!=4);
return 0;
}

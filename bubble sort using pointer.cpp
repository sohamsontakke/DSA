#include<iostream>
using namespace std;
/*int main()
{
	int n;
	cout<<"enter size ";
	cin>>n;
	int arr[n];
	cout<<"enter "<<n<<" elements";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int *p=&arr[0];
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (*(p+i) < *(p+j))
			{
				int t=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=t;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<"\n"<<*(p+i);
	}
	return 0;
}
*/

//structure using object
/*
struct node
{
    int data;
    string name;
};
int main()
{
    int n=4;
    struct node arr[n];
    for (int i=0;i<n;i++)
    {
        cout<<"ENTER DATA : ";
        cin>>arr[i].data;
        cout<<"ENTER NAME : ";
        cin>>arr[i].name;
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i].data<<" "<<arr[i].name<<endl;
    }
    return 0;
}*/

//structure using pointer variable
struct node
{
    int data;
    string name;
};
int main()
{
    int n=4;
    struct node arr[n];
    struct node *p =arr;
    for (int i=0;i<n;i++)
    {
        cout<<"ENTER DATA : ";
        cin>>(p+i) ->data;
        cout<<"ENTER NAME : ";
        cin>>(p+i) ->name;
    }
    for (int i=0;i<n;i++)
    {
        cout<<(p+i)->data<<" "<<(p+i)->name<<endl;
    }
    return 0;
}

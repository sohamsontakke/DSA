#include<iostream>
using namespace std;
int main()
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
		cout<<*(p+i);
	}
	return 0;
}

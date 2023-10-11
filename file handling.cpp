#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream New;
	New.open("ipl.txt",ios::app);
	if (!New)
	{
		cout<<"File is not found!!!";
	}
	else
	{
		New<<"\nHello";
		cout<<"File created!!!";
	}
	New.close();

	ifstream New1;
	New1.open("ipl.txt");
	if(!New1)
	{
		cout<<"file not found!!!";
	}
	else
	{
		string data;
		while(getline(New1,data))
		{
			cout<<data<<endl;
		}
	}
	New.close();
	return 0;
}

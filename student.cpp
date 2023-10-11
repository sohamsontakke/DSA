#include<iostream>
#include<fstream>
using namespace std;
void insert()
{
	ofstream f;
	f.open("Student.txt",ios::app);
	if (!f)
	{
		cout<<"File is not found!!!";
	}
	string roll,name,div,add;
	cout<<"Enter roll No : ";
	cin>>roll;
	cout<<"Enter Name : ";
	cin>>name;
	cout<<"Enter Divison : ";
	cin>>div;
	cout<<"Enter Address : ";
	cin>>add;
	string k=roll+"\t"+name+"\t"+div+"\t"+add+"\n";
	f<<k;
	f.close();
}
void display()
{
	string data;
	ifstream i;
	i.open("Student.txt",ios::in);
	if (!i)
	{
		cout<<"not Found";
		return;
	}
	cout<<"Roll No\tName\tDivison\tAddress"<<endl;
	while(getline(i,data))
	{
		cout<<data<<endl;
	}
	i.close();
}
void Delete()
{
	ifstream f; ofstream f1;
	f.open("Student.txt",ios::in);
	f1.open("text.txt",ios::out);
	if(!f || !f1)
	{
		cout<<"not Found !!";
		return;
	}
	string data;char key;
	cout<<"Enter roll no to delete : ";
	cin>>key;
	while(getline(f,data))
	{
		char d=data[0];
		if (d!=key)
		{
			f1<<data<<endl;
		}
	}
	f.close();
	f1.close();
	remove("Student.txt");
	rename("text.txt","Student.txt");
}
int main()
{
	int ch;
	while(ch!=4)
	{
		cout<<"\nMenu"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Delete"<<endl<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				Delete();
				break;		
		}
	}
	return 0;
}

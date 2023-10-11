#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
void insertData()
{
    ofstream f;
    f.open("Tcc.dat",ios::app);
    if(!f)
    {
        cout<<"file not found"<<endl;
        return;
    }
    string roll;
    char div;
    string name, add;
    //data from user
    cout<<"\nEnter Roll No of Student: ";
    cin>>roll;
    cout<<"\nEnter a Name of Student: ";
    cin>>name;
    cout<<"\nEnter a Division of Student: ";
    cin>>div;
    cout<<"\nEnter a Address of Student: ";
    cin>>add;

    string k=roll+"\t"+name+"\t"+div+"\t"+add+"\n";
    f<<k;
    //f<<name+"\t"+div+"\t"+add+"\t"<<k<<"\n";
    //f<<k+"\t"+name+"\t"+div+"\t"+add+"\n";
    f.close();

}
void displayData()
{
    fstream f;
    string data;

    if(!f)
    {
        cout<<"file not found"<<endl;
        return;
    }
    cout<<"Roll\tName\tDiv\tCity\n-------------------------------\n";
    f.open("Tcc.dat",ios::in);

    while (getline(f, data))
    {
        cout << data << "\n";
    }
    f.close();
}
void changeData()
{
    int ch;
    string udata;
    kkk:
    cout<<"1.By Roll Number\n2.By Name:\n";
    cin>>ch;
    cin.ignore();
    if(ch==1)
    {
        cout<<"Enter Roll number: "<<endl;
        cin>>udata;
    }
    else if (ch==2)
    {
        cout<<"Enter Name: "<<endl;

        cin>>udata;
    }
    else
    {
        cout<<"enter valid choice:  "<<endl;
        goto kkk;
    }
    fstream fin;
    ofstream fout;
    string data;
    if(!fin && !fout)
    {
        cout<<"file not found"<<endl;
        return;
    }
    fin.open("Tcc.dat",ios::in);
    fout.open("temp.dat",ios::out);
    int flag=0;
    while (getline(fin,data))
    {
        if(strstr(data.c_str(),udata.c_str()) && flag==0)
        {
            string roll,div,name, add;
            //data from user
            cout<<"\nEnter Roll No of Student: ";
            cin>>roll;
            cout<<"\nEnter a Name of Student: ";
            cin>>name;
            cout<<"\nEnter a Division of Student: ";
            cin>>div;
            cout<<"\nEnter a Address of Student: ";
            cin>>add;

            string k=roll+"\t"+name+"\t"+div+"\t"+add+"\n";
            fout<<k;
            flag=1;
        }
        else
        {
            fout<<data<<"\n";
        }
    }
    fin.close();
    fout.close();

    int res=remove("Tcc.dat");
    if(res==0)
        cout<<"Data Modified!!"<<endl;
    rename("temp.dat","Tcc.dat");
    fout.close();
}
void deleteData11()
{
    int ch;
    string udata;
    kkk:
    cout<<"1.By Roll Number\n2.By Name:\n";
    cin>>ch;
    cin.ignore();
    if(ch==1)
    {
        cout<<"Enter Roll number: "<<endl;
        cin>>udata;
    }
    else if (ch==2)
    {
        cout<<"Enter Name: "<<endl;

        cin>>udata;
    }
    else
    {
        cout<<"enter valid choice:  "<<endl;
        goto kkk;
    }
    fstream fin;
    ofstream fout;
    string data;
    fin.open("Tcc.dat",ios::in);
    fout.open("temp.dat",ios::out);
    if(!fin && !fout)
    {
        cout<<"file not found"<<endl;
        return;
    }
    int flag=0;
    while (getline(fin,data))
    {
    	int c=stoi(data);
//    	int c= stoi(data);
    	string d=atoi(c);
    	if (d!=udata)
    	{
    		fout<<data;
		}
//        if(!strstr(data.c_str(),udata.c_str()) && flag==0)
//        {
//            fout<<data<<"\n";
//        }
    }
    fin.close();
    fout.close();
    int res=remove("Tcc.dat");
    if(res==0)
        cout<<"Record Deleted!!!"<<endl;
    rename("temp.dat","Tcc.dat");
}
int main()
{
    int ch;
    while(1)
    {
        cout<<"\n1.Insert\n2.Display\n3.Delete:\n4.Chabge by Name or by Roll\n6.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                insertData();
                break;
            case 2:
                 displayData();
                break;
            case 3:
                deleteData11();
                break;
            case 4:
                changeData();
                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}

#include<iostream>
using namespace std;
int indx=-1;
int maxSize=10;
int arr[10];
void push()
{
    if (indx==maxSize)
    {
        cout<<"stack is full "<<endl;
    }
    else
    {
        int n;
        cout<<"Enter no :";
        cin>>n;
        arr[++indx]=n;
        cout<<"Element added "<<endl;
    }
}
void display()
{
    if (indx==-1)
    {
        cout<<"stack is empty "<<endl;
    }
    else
    {
        cout<<"Elements :- ";
        for (int i=0;i<=indx;i++)
        {
            cout<<arr[i]<<"  ";
        }
    }
}
void pop()
{
    if (indx==-1)
    {
        cout<<"Stack is empty : "<<endl;
    }
    else
    {
        indx--;
        cout<<"Element Removed "<<endl;
    }
}
void top()
{
    cout<<"Top most element is :- "<<arr[indx]<<endl;
}
int main()
{
    int ch;
    do
    {
        cout<<"\n\n****MENU****"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Display Elements"<<endl;
        cout<<"3.delete element"<<endl;
        cout<<"4.Display the top element in the stack"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            display();
            break;

        case 3:
            pop();
            break;

        case 4:
            top();
            break;
        }
    }while(ch!=5);
    return 0;
}

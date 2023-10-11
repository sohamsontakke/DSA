#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void LastInsert()
{
    int d;
    struct node *temp=new node;
    if (temp==NULL)
    {
        cout<<"OVERFLOW";
        return;
    }
    else
    {
        cout<<"ENTER DATA : ";
        cin>>d;
        temp->data=d;
        temp->next=NULL;
    }
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *ptr=head;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display()
{
    struct node *temp=head;
    cout<<"Elements :";
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void LastDelete()
{
    if (head==NULL)
    {
        cout<<"underflow";
        return;
    }
    else if (head -> next==NULL)
    {
        head=NULL;
        free(head);
    }
    else
    {
        struct node *temp=head;
        struct node *pretemp;
        while(temp ->next != NULL)
        {
            pretemp=temp;
            temp = temp->next;
        }
        pretemp->next=NULL;
        free(temp);
    }
    cout<<endl<<"element deleted successfully!!";
}
void BeginInsert()
{
    struct node *temp=new node();
    if (temp==NULL)
    {
        cout<<"overflow";
    }
    else
    {
        int n;
        cout<<"ENTER DATA : ";
        cin>>n;
        temp->data=n;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
}
void BeginDelete()
{
    if(head==NULL)
    {
        cout<<"underflow";
    }
    else if(head->next==NULL)
    {
        delete(head);
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        delete(temp);
    }
}
void AfterInsert()
{
    int n;
    cout<<"Enter position no to insert : ";
    cin>>n;
    struct node *ptr=head, *preptr;
    int pos=1;
    while(ptr!=NULL)
    {
        if (pos==n && ptr==head)
        {
            BeginInsert();
            break;
        }

        if(pos==n)
        {
            struct node *temp=new node();
            cout<<"Enter data";
            cin>>(temp->data);
            temp->next=ptr;
            preptr->next=temp;
            break;
        }
        pos++;
        preptr=ptr;
        ptr=ptr->next;

    }
    if(n>pos)
    {
        cout<<"POSITION IS HIGHER THAN COUNT";
    }
}
void DeleteAt()
{
    if (head==NULL)
    {
        cout<<"underflow";
    }
    else
    {
        int n;
        cout<<"ENTER POSITION TO DELETE : ";
        cin>>n;
        int pos=1;
        struct node *temp=head,*pretemp;
        while(temp != NULL)
        {
            if (pos==n && temp==head)
            {
                head=head->next;
                delete (temp);
                break;
            }
            else if (pos==n)
            {
                pretemp->next=temp->next;
                delete temp;
                break;
            }
            pos++;
            pretemp=temp;
            temp=temp->next;
        }
        if (n>pos)
        {
            cout<<"DATA NOT FOUND ";
        }
    }
}
void Count()
{
    struct node*temp=head;
    int cnt=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    cout <<"no of nodes : "<<cnt<<endl;
}
int main()
{
    int ch;
    cout<<"*****MENU******"<<endl;
    cout<<"1.Enter at beginning"<<endl;
    cout<<"2.Enter at Ending"<<endl;
    cout<<"3.Remove from beginning"<<endl;
    cout<<"4.Remove from Ending"<<endl;
    cout<<"5.Enter at Middle"<<endl;
    cout<<"6.Remove from Middle"<<endl;
    cout<<"7.Total no of nodes"<<endl;
    cout<<"Enter your choice";
    cin>>ch;
    switch(ch)
    {
    case 1:
        BeginInsert();
        break;

    case 2:
        LastInsert();
        break;

    case 3:
        BeginDelete();
        break;

    case 4:
        LastDelete();
        break;

    case 5:
        AfterInsert();
        break;

    case 6:
        DeleteAt();
        break;

    case 7:
        Count();
        break;

    default:
        cout<<"Invalid choice !! ";
        break;
    }
    return 0;
}

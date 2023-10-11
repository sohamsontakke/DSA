#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head=NULL,*tail=NULL;
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
            head=tail=temp;
        }
        else
        {
            temp->next=head;
            head->pre=temp;
            head=temp;
        }
    }
}
void revdisplay()
{
    struct node *temp=tail;
    cout<<"Elements :";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->pre;
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
        head=tail=NULL;
        delete(head);
        delete(tail);
    }
    else
    {
        struct node *temp=head->next;
        temp->pre=NULL;
        delete(head);
        head=temp;
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
        tail=NULL;
        free(head);
        free(tail);
    }
    else
    {
        struct node *temp=tail->pre;
        temp->next=NULL;
        free(tail);
    }
    cout<<endl<<"element deleted successfully!!";
}
void LastInsert()
{
    struct node *temp=new node;
    if (head==NULL)
    {
        BeginInsert();
    }

    else
    {
        cout<<"Enter data : ";
        cin>>temp->data;
        tail->next=temp;
        temp->pre=tail;
        tail=temp;
    }
}
void AfterInsert()
{
    int n;
    cout<<"Enter position no to insert : ";
    cin>>n;
    struct node *ptr=head, *preptr;
    int pos=1;
    while(ptr->next !=NULL)
    {
        if (n==1)
        {
            BeginInsert();
            break;
        }

        else if(pos==n)
        {
            struct node *temp=new node();
            cout<<"Enter data";
            cin>>(temp->data);
            temp->next=ptr;
            ptr->pre=temp;
            preptr->next=temp;
            temp->pre=preptr;
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
            if (pos==n && temp==head && head->next==NULL)
            {
                //head=NULL;
                delete (head);
                break;
            }
            if (pos==n && temp==head)
            {
                head=temp->next;
                head->pre=NULL;
                delete (temp);
                break;
            }
            else if(pos==n && temp==tail)
            {
               pretemp->next=NULL;
               free(tail);
               tail=pretemp;
            }
            else if (pos==n)
            {
                struct node *x=temp->next;
                pretemp->next=x;
                x->pre=pretemp;
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
    while(1)
    {
    int ch;
    cout<<"\n*****MENU******"<<endl;
    cout<<"1.Enter at beginning"<<endl;
    cout<<"2.Enter at Ending"<<endl;
    cout<<"3.Remove from beginning"<<endl;
    cout<<"4.Remove from Ending"<<endl;
    cout<<"5.Enter at Middle"<<endl;
    cout<<"6.Remove from Middle"<<endl;
    cout<<"7.Total no of nodes"<<endl;
    cout<<"8.Display the elements"<<endl;
    cout<<"9.Exit the program"<<endl;
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

    case 8:
        revdisplay();
        break;

    case 9:
        exit(0);
        break;

    default:
        cout<<"Invalid choice !! ";
        break;
    }
    }
    return 0;
}

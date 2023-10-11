#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *head=NULL,*end=NULL;
void BeginInsert()
{
    struct node *temp=new node();
    if (temp==NULL)
    {
        cout<<"overflow";
    }
    temp->pre=temp->next=NULL;
    else
    {
        if (head==NULL)
        {
            head=end=temp;
        }
        else
        {
            temp->next=head;
            head->pre=temp;
            head=temp;
        }
    }
}
int main()
{
    BeginInsert();
    return 0;
}

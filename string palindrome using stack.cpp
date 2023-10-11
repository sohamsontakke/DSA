#include<iostream>
#define maxSize 10
using namespace std;
int index=-1;
char arr[maxSize +1];
void push (char k)
{
    if (index==maxSize)
    {
        cout<<"stack is Full";
    }
    else
    {
        arr[++index]=k;
    }
}
char pop ()
{
    if (index==-1)
    {
        cout<<"stack is empty";
    }
    else
    {
        char k=arr[index];
        index--;
        return k;
    }
    return '1';
}

int main()
{
    string input;
    cout<<"Enter any string : ";
    cin>>input;
    int b=0;
    for (int i=0;i<input.length();i++)
    {
        char k=input[i];
        push (k);
    }
    for (int i=0;i<input.length();i++)
    {
        char k=input[i];
        if (k!=pop())
        {
            cout<<"Not palindrome ";
            b=1;
            break;
        }
    }
    if (b==0)
    {
        cout<<"Palindrome string ";
    }
    return 0;
}


#include<iostream>
#define maxSize 10
using namespace std;
int index=-1;
int arr[maxSize +1];
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
int pop ()
{
    if (index==-1)
    {
        cout<<"stack is empty";
    }
    else
    {
        int k=arr[index];
        index--;
        return k;
    }
    return 0;
}

int main()
{
    string input;
    cout<<"Enter postfix exp : ";
    cin>>input;
    int b=0;
    for (int i=0;i<input.length();i++)
    {
        int res;
        char k=input[i];
        if (k>='0' && k<='9')
        {
            push (k-'0');
        }
        else
        {
            int n2=pop(),n1=pop();
            switch(k)
            {
            case '+':
                res=n1+n2;
                break;

            case '-':
                res=n1-n2;
                break;

            case '*':
                res=n1*n2;
                break;

            case '/':
                res=n1/n2;
                break;
            }
            push(res);
        }
    }
    cout<<pop()<<endl;
    return 0;
}





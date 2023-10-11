#include<iostream>
#define maxSize 10
using namespace std;
char arr[maxSize];
int index=-1;
void push(char k)
{
    arr[++index]=k;
}
char pop()
{
    char k=arr[index];
    index--;
    return k;
}
int priority(char k)
{
    if (k=='+' || k=='-')
    {
        return 1;
    }
    else if (k=='*' || k=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string exp,out="";
    cout<<"Enter your Expression : ";
    cin>>exp;
    int i=0;
    while (exp[i]!='\0')
    {
        char k=exp[i];
        if (k>='a' && k<='z')
        {
            out=out+k;
        }
        else if (k=='(')
        {
        	push(k);
		}
		else if (k==')')
		{
			while (arr[index]!='(')
			{
				out=out+pop();
			}
			pop();
		}
        else
        {
            while (priority(arr[index]) >= priority(k))
            {
                out=out+pop();
            }
            push(k);

        }
        i++;
    }
    while (index>=0)
    {
        out=out+pop();
    }
    cout<<"Expression : "<<out;
    return 0;
}

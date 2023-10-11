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
    cout<<"Enter your Infix Expression : ";
    cin>>exp;
    for (int i=exp.length();i>=0;i--)
    {
        char k=exp[i];
        if (k>='a' && k<='z')
        {
            out=out+k;
        }
        else if (k==')')
        {
        	push(k);
		}
		else if (k=='(')
		{
			while (arr[index]!=')')
			{
				out=out+pop();
			}
			pop();
		}
        else
        {
            while (priority(arr[index]) > priority(k))
            {
                out=out+pop();
            }
            push(k);

		}      
	}
	while (index>=0)
    	{
        	out=out+pop();
    	}
	cout<<"postfix expression is : "<<out<<endl;
	cout<<"Prefix expression is : ";
	for (int i=out.length();i>=0;i--)
	{
		cout<<out[i];
	}
    return 0;
}

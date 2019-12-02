#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxsize=10;
class stack
{
    char a[maxsize];
    int top;
public:
    stack()
    {
        top=-1;
    }
    void push(char);
    char pop();
    char topele();
    void display();
    int isempty();
};
void stack::push(char ele)
{
    if(top==maxsize-1)
    {
        cout<<"\n stack is full";
    }
    else
    {
        top=top+1;
        a[top]=ele;
    }
}
char stack::pop()
{
    char ele;
    if(top==-1)
    {
        return('x');
    }
    else
    {
        ele=a[top];
        top=top-1;
        return(ele);
    }
}
char stack::topele()
{
    return(a[top]);
}
void stack::display()
{
    int i;
    if(top==-1)
    {
        //cout<<"\n stack is empty";
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            cout<<a[i];
        }
    }
}
int stack::isempty()
{
    if(top==-1) return(1);
    else return(0);
}
enum precedence
{
    lparen,rparen,add,sub,times,divide,mod,eos,operand
};
int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};
precedence get_token(char c)
{
    switch(c)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return add;
        case '-': return sub;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        default: return operand;
    }
}
void prefix(char infix[])
{
    precedence temp;
    char prefix[20];
    int i,j=0;
    for(i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
        {
            infix[i]=')';
        }
        else if(infix[i]==')')
        {
            infix[i]='(';
        }
    }
    i=strlen(infix)-1;
    stack s;
    while(i>=0)
    {
        temp=get_token(infix[i]);
        if(temp==operand) prefix[j++]=infix[i];
        else if(temp==rparen)
        {
            while(get_token(s.topele())!=lparen)
            {
                prefix[j++]=s.pop();
            }
            char c=s.pop();
        }
        else
        {
            if(s.isempty())
            {
                s.push(infix[i]);
            }
            else
            {
                while(icp[temp]<isp[get_token(s.topele())]&&s.isempty()==0)
                {
                    prefix[j++]=s.pop();
                }
                s.push(infix[i]);
            }
        }
        i--;
    }
    while(s.isempty()==0)
    {
        prefix[j++]=s.pop();
    }
    for(i=j-1;i>=0;i--)
    {
        cout<<prefix[i];
    }
}
int main()
{
    char infix[20];
    cout<<"enter an infix expression ";
    cin>>infix;
    prefix(infix);
    return(0);
}

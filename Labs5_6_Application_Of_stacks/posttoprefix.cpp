#include <iostream>
#include <ctype.h>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int MAX = 50;
class stack1
{
    int top;
    char s[MAX][MAX];
    public :
    stack1(){top = -1;}
//    void push(char a[]);
 //   char *pop();
char* pop()
{
    if(top == -1)
    {
        return "X";
    }
    else
    {
        return s[top--];
    }
}
void push(char a[])
{
    top++;
    strcpy(s[top], a);
}


};


int isOperator(char c)
{

    switch (c)
    {

    case '+' :
    case '-' :
    case '/' :
    case '*' :
    case '%' :
        return 1;
    }
    return 0 ;
}

char* pre_post(char pre[ ])
{
    int i, len;
    stack1 obj;
    char t1[100], t2[100], t3[100];
    char op1[10], op2[10], opr[10];

    for(i = 0 ;i <pre[i]!='\0' ; i++)
    {
        if(isOperator(pre[i]))
        {
            strcpy(t2 ,obj.pop());
            strcpy(t1 ,obj.pop());


    strcat(t1,t2);
    t3[0]=pre[i];
    t3[1]='\0';
    strcat(t3,t1);
    obj.push(t3);
        }
        else
        {
            t1[0] = pre[i]; t1[1] ='\0';
            obj.push(t1);
        }
}
cout<<(obj.pop());
}
int main()
{
    char arr[50];
    gets(arr);
    pre_post(arr);
}

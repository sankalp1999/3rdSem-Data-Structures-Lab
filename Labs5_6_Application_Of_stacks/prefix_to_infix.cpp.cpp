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
    void push(char a[]);
    char *pop();
};
void stack1 ::push(char a[])
{
    top++;
    strcpy(s[top], a);
}
char* stack1 :: pop()
{
    if(top == -1)
    {
        return "x";
    }
    else
    {
        return s[top--];
    }
}
void prefix_infix()
{
    stack1 obj;
    char op1[30], op2[30], operator1[30];
    char symbol[30], prefix[30];
    cout << "Please enter a prefix expression." << endl;
    gets(prefix);
    for(int i = strlen(prefix) - 1 ; i>= 0 ; i--)
    {
        char temp1[30], temp2[30];
        temp1[0] = prefix[i];
        temp1[1] =  '\0';
        strcpy(symbol, temp1);
        if(!isalpha(prefix[i]))
        {
        strcpy(op1, obj.pop());
        strcpy(op2, obj.pop());
        strcpy(temp2, "(");
        strcat(temp2, op1);
        strcat(temp2, symbol);
        strcat(temp2, op2);
        strcat(temp2, ")");
        obj.push(temp2);
        }
        else{obj.push(symbol);

        }
    }
    cout << "Result : " << obj.pop();
}
int main()
{
    prefix_infix();
    return 0;
}

#include <iostream>
#include <cstring>
#include  "stack2.cpp"
using namespace std;
void postfix_evaluation()
{

    stack1 obj ;
    int digit, op1, op2, res;
    char token, postfix[50] ;
    cout << "Enter the prefix expression. " ;
    gets(postfix);
    for(int i = strlen(postfix) - 1 ; i >=0 ; i--)
    {

        token = postfix[i];

        if(token >= 48 && token <= 57)
        {
            digit = token - '0';
            obj.push(digit);
        }
        else if(token == '+' || token == '-' || token == '*' || token == '/' || token == '%')
        {
            op1 = obj.pop();
            op2 = obj.pop();

        switch(token)
        {
            case '%' : obj.push(op1%op2); break;
            case '/' : obj.push(op1/op2); break;
            case '+' : obj.push(op1 + op2 ); break;
            case '-': obj.push(op1- op2 ); break;
            case '*' : obj.push(op1*op2); break;
        }
        }
        else // if alphabet
        {
            cout << "Enter " << token << " 's value" ;
            int val;
            cin >> val;
            obj.push(val);

        }
    }
    cout << "Result of evaluation : " << obj.pop() ;
}
int main()
{

    postfix_evaluation();
    return 0;

}


#include <iostream>
#include <cstdio>
using namespace std;

#define max1 10
class stack1{
private :
    char a[max1]; // max size of the array
    int top;
    int ele; // top element
public :
    // constructor
    stack1()
    {
        top = -1; // initialization to -1
    }

    // all the operations
    int pop();
    int topele();
    void push(char i);
    void display();
    bool isEmpty();

};
bool stack1 :: isEmpty()
{

    if (top == -1 )
    {
        return true;
    }
    else
        {return false;}
}
int stack1::topele()
{
    if (top != -1)
    {return a[top];}
    else
    {
        //cout << "The stack is empty.";
        return -999;
    }

}
int stack1::pop()
{
    if (top == - 1)
    {
        //cout << "The stack is empty.";
        return -999;
    }
    else
    {
        //cout << "The popped element is : "<< a[top] << endl;
        ele = a[top];
        top--; // decrementing the top
        return ele;
    }
}
void stack1::push(char i)
{
    if (top == max1 - 1)
    {
        cout << "The stack is full." << endl;
    }
    top = top + 1 ;
    a[top] = i;
}
 void stack1 ::display()
{
    int i ;
    if ( top == -1)
    {
        //cout << "The stack is empty and there is nothing to display." << endl;
    }
    for(int j = top ; j >= 0 ; j--)
    {

        cout << a[j] << "\n ---- \n";
    }
}
int main()
{
    stack1 s1 ;

    char arr[100];
    char out[100];
    cout << "Please enter the sequence of brackets." << endl;
    int flag = 1;
    fflush(stdin);
    gets(arr);
    for(int i = 0 ; arr[i] != '\0' ; i++ )
    {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{'  )
                {
                    s1.push(arr[i]);
                }
        else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            if (s1.isEmpty())
            {
                flag = 0 ;
                break;
            }
            if (s1.topele() == '(' && arr[i] == ')')
            {
                s1.pop();
                continue;
            }

            if ((s1.topele() == '[' && arr[i] == ']'))
            {
                s1.pop();
                continue;
            }

            if((s1.topele() == '{' && arr[i] == '}'))
            {
                s1.pop();
                continue;
            }
        }
    }
    s1.display();
    if ( s1.isEmpty() && flag == 1)
    {
        cout << "The sequence is balanced." << endl;
    }
    else if ( flag == 0 || s1.isEmpty() == 0)
    {
        cout << "The sequence is  not balanced." << endl;
    }

    return 0;
}


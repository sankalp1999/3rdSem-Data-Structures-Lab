#include <iostream>
#include <cstdio>
using namespace std;

#define max1 10

class stack1{
private :
    int a[max1]; // max size of the array
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
    void push(int i);
    void display();
};

int stack1::topele()
{
    if (top != -1)
    {return a[top];}
    else
    {
        cout << "The stack is empty.";
        return -999;
    }

}

int stack1::pop()
{
    if (top == - 1)
    {
        cout << "The stack is empty.";
        return -999;
    }
    else
    {
        cout << "The popped element is : "<< a[top] << endl;
        ele = a[top];
        top--; // decrementing the top
        return ele;
    }
}

void stack1::push(int i)
{
    if (top == max1 - 1)
    {
        cout << "The stack is full." << endl;
    }
    top = top + 1 ;
    a[top] = i;
}

 void stack1::display()
{
    int i ;
    if ( top == -1)
    {
        cout << "The stack is empty and there is nothing to display." << endl;
    }
    for(int j = top ; j >= 0 ; j--)
    {

        if (a[j] >= 65 )
        {cout << "  " << (char)a[j] << "\n ---- \n";}
        else
        {
            cout << "  " << a[j] << "\n ---- \n";
        }
    }
}

int main()
{
    stack1 s1 ;
    int flag = 1 ;
    int num, ele, pushele ;
    int base ;
    char arr[100];
    char out[100];
    cout << "Please enter a integer for the base representation you want." << endl;
    cin >> num ;
    cout << "Please enter the base." << endl;
    cin >> base;
    while( num != 0 )
    {
        ele = num % base;
        if (ele > 9 )
        {
            s1.push(ele - 10 + 'A');
        }
        else
        {

        s1.push(ele);
        }

        num = num/base;
    }

    s1.display();

    return 0;
}


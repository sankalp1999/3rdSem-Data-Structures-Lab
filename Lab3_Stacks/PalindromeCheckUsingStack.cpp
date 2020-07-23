#include <iostream>
#include <cstdio>
using namespace std;

#define max1 10
class stack1{
private :
    char a[max1];
    int top;
    int ele;
public :
    stack1()
    {
        top = -1;
    }
    int pop();
    int topele();
    void push(char i);
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
        top--;
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
        cout << "The stack is empty and there is nothing to display." << endl;
    }
    for(int j = top ; j >= 0 ; j--)
    {

        cout << a[j] << "\n ---- \n";
    }
}

int main()
{
    stack1 s1 ;
    int flag = 1 ;
    char arr[100];
    char out[100];
    cout << "Please enter a string you want to invert." << endl;
    
    fflush(stdin); // Lab compilers are weird.
    gets(arr);
    
    for(int i = 0 ; arr[i] != '\0'; i++)
    {
        s1.push(arr[i]);
    }
    for(int i = 0 ; arr[i] != '\0'; i++)
    {
        out[i] = s1.pop();
    }
    int len = 0 ;
    
//     for( len = 0 ; arr[len] != '\0'; len++)
        
    for(int i = 0 ; i<  len/2 ; i++)
    {
        if(out[i] == arr[i])
        {
            continue;
        }
        else
        {
            flag = 0 ;
            break;
        }
    }
    
    if (flag == 1 )
    {
        cout << "The string is a palindrome.";
    }
    else if (flag == 0 )
    {

        cout << "The string is not a palindrome." ;
    }
    return 0;
}


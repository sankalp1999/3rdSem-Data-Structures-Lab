#include <iostream>
#include <cstdio>
using namespace std;

#define max1 20
class stack1{
private :
    char a[max1];
    int top;

public :

    stack1()
    {
        top = -1;
    }
    char pop();
    char topele();
    void push(char i);
    void display();
    int isEmpty();
};
int stack1:: isEmpty()
{
	if(top == -1)
	{
		return 1 ;
	}
	return 0 ;
}
char stack1::topele()
{
   // if(top != -1)
   //{
     return a[top];
   //}

}
char stack1::pop()
{
        char ele = a[top];
        top--;
        return ele;
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





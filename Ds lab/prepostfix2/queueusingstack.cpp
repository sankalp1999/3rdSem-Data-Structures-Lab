#include <iostream>
#include "stack1.cpp"
using namespace std;
class QusingStack{

    stack1 s1, s2;
    public :
    void enQ(char ele)
    {
        while(!s1.isEmpty())
    {
        s2.push(s1.pop());
    }
    s1.push(ele);
    while(!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
    }
    void dQ()
    {
        if(s1.isEmpty())
        {
            cout << "Q is empty." << endl;
        }
        else
        {
            cout <<  s1.pop();
        }
    }
    void display()
    {
        s1.display();
    }
};
int main()
{
    QusingStack q ;
    q.enQ('a');
    q.enQ('b');
    q.enQ('c');
    q.display();
}

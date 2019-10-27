#include <cstdio>
#include <iostream>
using namespace std;
const int ns = 3 ;
#define MAX 9   // MAX is maxsize of the stack
class mstack
{
private:
    int top[ns], bottom[ns];
    int s[MAX];
public :
    mstack()
{   // initializing the top and bottom
    for(int i = 0 ; i < ns ; i++)
    {
        top[i] = (MAX/ns)*i - 1; // maxsize/number of stacks - 1 gives us each top value.
        bottom[i] = (MAX/ns)*i - 1;// bottom will remain fixed.


    }

}
    void push(int ele, int i)
{
    if(top[i] == bottom[i+1] || top[i] == MAX - 1 )
    {
        cout << i << " th stack is full" << endl ;

    }
    else
    {
        top[i]++; // first increment the i of the ith stack
        s[top[i]] = ele; // insert
    }
}
    int pop(int i)
{
    if (top[i] == bottom[i])
    {
        cout << "Stack " << i+1 << " is empty." << endl;
        return -999;
    }
    else
    {
        int ele = s[top[i]];
        top[i]--;
        return ele;
    }

}
    void display(int i)
{
        if (bottom[i] == top[i])
        {
            cout << "Stack " << i+1 << "is empty." << endl;
        }
        else
        {
            cout << "   Stack :  " << i+1 << endl;


            for(int j=top[i]; j > bottom[i]; j--)
            {

                cout << s[j] << endl; // display for the ith stack
            }
            cout << "------------" << endl;
        }



}
    int topele(int i)
{
    if (top[i] == bottom[i] )
    {
        cout << "Stack is empty." << endl;
        return -999;
    }
    else
    {
        return s[top[i]] ;
    }
}
};


int main()
{
    mstack s;
    // In the program, pass the i according to 0 indexing. So, for 2nd stack, pass 1
    s.push(5, 1); // Stack 2
    s.push(100, 1);
    s.push(1000, 1);
    s.pop(2);
    s.push(500, 2);
    s.push(100, 2);
    s.push(200, 2);
    s.pop(1);
    cout << s.topele(2) << endl ;


    s.display(1);
    s.display(2);


    return 0 ;

}

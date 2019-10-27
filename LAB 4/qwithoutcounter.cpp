#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 5
using namespace std;

class queue
{
private:

    int r, f; // rear and front

    int size1 = MAX - (r%MAX-f%MAX)%MAX;
    int q[MAX];
public:
    queue()
    {

        f = r = -1;
        int q[MAX];

    }
    void enqueue(int ele)
    {   // Max - 1 is used because at full size it will become 0 due to mod
        if(size1  == MAX - 1 && r!=f )
        {
            cout << "CQ is full" << endl;
        }
        else
        {

            r = (r+1); // MAX is the max size
            q[r] = ele;
      //      counter++;
        }
    }
    int deque()
    {
        if (r ==  f )
        {
            cout << "CQ is empty." << endl;
            return -999;
        }

        f = (f+1);

        return q[f];// returns the deleted element
    }
    void display()
    {
        int i ;
        if(r == f )
        {
            cout << "CQ is empty." << endl;
        }
        else
        {   //cout << q[0] << endl;
            for(i = (f+1); i <= r ; i = (i + 1) )
            {
               //cout << "i : " << i << " r : " << r << endl ;
                cout << q[i] << " | " ;

            }
        }

    }
};
int main()
{
    queue q;

    q.enqueue(5);
    //q.display();
    q.enqueue(100);
    q.enqueue(13878);
    q.enqueue(10000);
    q.enqueue(1000);
    q.enqueue(-1000);
    q.display();
    q.deque();
    q.deque();
    q.deque();
    cout << endl;

    q.display();
    q.enqueue(120);
    q.enqueue(12100);
  //  q.enqueue(-1);
    q.enqueue(100);
    q.enqueue(100);
    q.display();
    return (0) ;
}

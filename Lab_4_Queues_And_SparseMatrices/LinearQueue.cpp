
#include <iostream>
#include <cstdio>
#define MAX 5
using namespace std;

class queue
{
private:

    int r, f; // rear and front
    int counter;
    int q[MAX];
public:
    queue()
    {
        f = r = -1;
        int q[MAX];
        counter = 0 ;
    }
    void enqueue(int ele)
    {
        if(counter == MAX)
        {
            cout << "CQ is full" << endl;
        }
        else
        {
            r = (r+1); // MAX is the max size
            q[r] = ele;
            counter++;
        }
    }
    int deque()
    {
        if (counter == 0 )
        {
            cout << "CQ is empty." << endl;
            return -999;
        }
        f = (f+1);
        counter -= 1 ;
        return q[f];// returns the deleted element
    }
    void display()
    {
        int i ;
        if(counter == 0)
        {
            cout << "CQ is empty." << endl;
        }
        else
        {   //cout << q[0] << endl;
            for(i = (f+1); i <= r ; i = (i + 1) )
            {
              //  cout << "i : " << i << " r : " << r << endl ;
                cout << q[i] << " | " ;
            }
        }
    }
};
int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(100);
    q.enqueue(13878);
    q.display();
    q.deque();
    q.deque();
    q.deque();
    q.display();
    q.enqueue(120);
    q.enqueue(12100);
    q.enqueue(-1);
    q.enqueue(100);
    q.display();
    return 0;
}

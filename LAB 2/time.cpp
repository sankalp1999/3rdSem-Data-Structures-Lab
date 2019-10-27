#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;
int abso(int i)
{
    if (i < 0 )
    {
        return (i*-1);

    }
}
class time{
    private :
        int hour,minute,sec ;
    public :
    time() // default constructor
    {   hour = 0 ;
        minute = 0 ;
        sec = 0  ;         }
    time(int h, int m, int s)   // constructor
    {
        hour = h + m/60 ;
        minute = (m  + s/60)% 60  ;
        sec = s % 60 ;
    }
    void add(time t1,time t2)
    {
        sec = (t1.sec + t2.sec)%60;
        minute = (t1.minute + t2.minute + (t1.sec + t2.sec)/60)%60;
        hour = minute/60 ;
        hour = hour  + t1.hour + t2.hour;
    }
    void subtract(time t1, time t2)
    {
    t1.sec = t1.hour*3600 + t1.minute*60 + t1.sec*1;
    t2.sec = t2.hour*3600 + t2.minute*60 + t2.sec*1;
    sec = abso(t1.sec - t2.sec);
    hour = sec/3600;
    minute = (sec%3600)/60;
    sec = (sec%3600)%60;
    }
    void display()
    {
        cout << "The time is as : " << endl;
        cout << hour << " hours " << minute << " minutes " << sec << " seconds " << endl;
    }


};
int main()
{
    time t1(2,30,35);
    time t2(4,10,25);
    time t3 ;
    t3.subtract(t2,t1);
    t1.display();
    cout << endl;
    t3.display();
    cout << "hello " << endl;
}

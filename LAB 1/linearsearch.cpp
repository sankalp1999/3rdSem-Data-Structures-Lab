#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, pos;
    cout << "Please enter the number which you want to enter.";
    cin >> n ;
    //cout << n << endl;
    int flag = 0;
    int arr[10] = { 1,2,34,6,100,9 ,1000, 10000, 10000,0};

    for(int i = 0; i<10;i++)
    {
        if (arr[i] == n)
        {
            flag = 1 ;
            pos = i ;
            cout << "The element has been found at position :" << pos ;

            break;
        }
    }
    if (flag == 0)
    {
        cout << "The element could not be found in the array.";
    }

    return 0;



}

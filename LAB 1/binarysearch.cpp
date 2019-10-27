#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int key, pos;
    cout << "Please enter the number which you want to enter.";
    cin >> key ;
    cout << "The entered key is as : " << key << endl;
    int flag = 0;
    vector<int> v(100,0);
    for(int i = 0 ; i < 100 ; i++)
    {
        v[i] = i;
    }
     for(int i = 0 ; i < 100 ; i++)
    {
        //cout << v[i] << " ";
    }
    int low, high, mid;
    high = v.size() - 1 ;
    low = 0 ;
    mid = (high+low)/2;

    while(low<= high)
    {
         mid = (low + high)/2;
        if (key == v[mid])
        {   int pos = mid;
            cout << "The element has been found at position : " << mid << endl;
            break;
        }
        else if (v[mid] < key)
        {
            low = mid + 1 ; ;// high will change
        }
        else if (v[mid] > key)
        {
         high = mid - 1;

        }
    }
    cout << "I reached end of execution.";



    return 0;



}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int key, pos;
   // cout << "Please enter the number which you want to enter.";
   // cin >> key ;
   // cout << "The entered key is as : " << key << endl;
    int flag = 0;
    //vector<int> v(100,0);
    int arr[100] ={0};

    int len = 10;
    int j = 0 ;
    for(int i = len -1; i >= 0  ; i--)
    {
         arr[j++] = i;

    }
    for(int i = 0 ; i<len  ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    for(int pass = 0; pass < len  ;pass++)
    {   int small = arr[pass];
        for(int j = pass + 1  ; j < len  ; j++)
        {
            int temp = arr[j];
            if (temp < small)
            {
                small = temp;
                pos = j;
            }
            int temp2 = arr[pass];
            arr[pass] = arr[j];
            arr[j]= temp2 ;
                  for(int i = 0 ; i<len  ; i++)
    {
        cout << arr[i] << " " ;
    }cout << endl;
        }



    }
     for(int i = 0 ; i < len  ; i++)
    {
        cout << arr[i] << " " ;
    }
    return 0;



}

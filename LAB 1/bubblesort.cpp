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
    int len = 100;
    int j = 0 ;
    for(int i = len -1  ; i >= 0  ; i--)
    {
         arr[j++] = i;

    }
    for(int i = 0 ; i < len  ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    for(int i = 0; i < len -1 ;i++)
    {   cout << "pass is as : " << i+1 << endl ;
        for(int j = 0 ; j < len - i ; j++)
            if (arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            cout << "swaps are as : " << arr[j] << " " << arr[j+1] << endl;
        }
    }
     for(int i = 0 ; i < len  ; i++)
    {
        cout << arr[i] << " " ;
    }
    return 0;



}

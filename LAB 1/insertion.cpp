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
    int n ;
    cin >> n ;
    cout << "Please enter the length of the array.";
    int arr[n+1] ={0};
    int len = n;
    int j = 0 ;
    for(int i = 0 ; i < n ; i++ )
    {
        cin >> arr[i];

    }
  //  for(int i = len -1; i >= 0  ; i--)
/*
    {
         arr[j++] = i;

    }
*/
    for(int i = 0 ; i<len  ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << "After sorting: \n";
    cout << endl;
    int count = 0 ;
    for(int pass = 1; pass < len  ;pass++)
    {   int item;
    count = 0 ;
        {
            item = arr[pass];
            j = pass - 1  ;
            while(j>=0 && arr[j] > item)
            {
                arr[j+1] = arr[j];
                j--;
                count++;
            }
                arr[j+1] = item ;
                for(int i = 0 ; i < len  ; i++)
    {
        cout << arr[i] << " "  ;
    }
    cout << " j: " << j << " " << count << endl;

        }
    }

    return 0;



}

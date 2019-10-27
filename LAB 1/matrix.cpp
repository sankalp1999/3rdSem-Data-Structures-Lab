#include <iostream>
using namespace std;
void display(int arr[][3])
{
      cout << endl;
      for(int i = 0; i< 3;i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3]; // first testing for 3 elements.
    cout << "Please input the elements of the first matrix.";
    for(int i = 0; i< 3;i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cin >> arr[i][j];
        }
    }
  display(arr);
  cout << "Please input the elements of the second matrix.";
  int arr2[3][3];
  for(int i = 0; i< 3;i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cin >> arr2[i][j];
        }
    }

  display(arr2);
  int sum[3][3];
   for(int i = 0; i< 3;i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            sum[i][j] = arr[i][j] + arr2[i][j];
        }
    }

    display(sum);

return 0;


}

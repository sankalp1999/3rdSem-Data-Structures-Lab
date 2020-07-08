


#include <iostream>

using namespace std;
class sparse
{
    int row, col, value;
public:
    sparse(int r, int c, int v)
    {
        row = r ;
        col = c ;
        value = v ;
    }
    // sparse is basically an object in a form of array.
    sparse()
    {
        row = col = value = 0 ;
    }
    void display(sparse s[ ]);
    void convert(sparse s[ ], int [][6]);
    void transpose(sparse s[ ] , int[][6]);
};
void sparse :: transpose(sparse s[ ],  int mat[][6])
{
     cout << "  TRANSPOSE " << endl;
     for(int i = 1 ; i <=  s[0].value ; i++)
    {
        int r = s[i].row;
        int c = s[i].col;
        int value = s[i].value;
        mat[c][r] = value;
    }
    for(int i =0 ; i < s[0].col; i++)
{   for(int j = 0 ; j < s[0].row; j++)
    {
        cout << mat[i][j] << " ";
    }   cout << endl;
}
}
void sparse::display(sparse s[])
{
    cout << "\n row \t col \t value \n" ;
    for(int i =0  ; i <= s[0].value; i++)
    {
        cout << "\n" << s[i].row << "\t" << s[i].col << "\t" << s[i].value;
    }
}
void sparse::convert(sparse s[], int mat[][6])
{
    for(int i = 1 ; i <=  s[0].value ; i++)
    {
        int r = s[i].row;
        int c = s[i].col;
        int value = s[i].value;
        mat[r][c] = value;
    }
    for(int i =0 ; i < s[0].row; i++)
{   for(int j = 0 ; j < s[0].col; j++)
    {
        cout << mat[i][j] << " ";
    }   cout << endl;
}

}
int main()
{
    sparse s[20];
    int r, c, v;
    int nzv = 0 ;
    int mat[6][6] = {};
    cout << "Enter the number of the rows." << endl;
    cin >> r ;
    cout << "Enter the number of the columns." << endl;
    cin >> c;
    cout << "Please enter the elements of the matrix." << endl;
    for(int i = 0; i < r ; i++)
    {
        for(int j=0; j< c ; j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < r ; i++)
    {
        for(int j=0; j< c ; j++)
        {
          if (mat[i][j] != 0)
          {
              nzv++;
          }
        }
    }


}








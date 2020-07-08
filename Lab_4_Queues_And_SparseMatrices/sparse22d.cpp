
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
    void display(sparse s[]);
    void convert(sparse s[], int [][6]);
};
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
    cout << "Enter the number of the rows." << endl;
    cin >> r ;
    cout << "Enter the number of the columns." << endl;
    cin >> c;
    cout << "Enter the number of the non-zero values." << endl;
    cin >> v ;
    int mat[6][6] = {};
    s[0] = sparse(r,c,v); // this is the header of the sparse matrix row major representation

    int nzv = v ; // nzv : no of non-zero values
    for(int i = 1  ; i <= nzv; i++)
    {
        cout << "\n row" << i << ":";
        cin >> r ;
        cout << "\n col" << i << ":";
        cin >> c;
            cout << "\n value" << i << ":";
        cin >> v ;
        s[i] = sparse(r,c,v);
    }

    s[0].display(s);
    cout << endl;
    s[0].convert(s, mat);
}








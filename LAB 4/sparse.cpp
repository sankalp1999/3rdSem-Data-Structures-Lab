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
};
void sparse :: display(sparse s[])
{
    cout << "\n row \t col \t value \n" ;
    for(int i =0  ; i <= s[0].value; i++)
    {
        cout << "\n" << s[i].row << "\t" << s[i].col << "\t" << s[i].value;
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
}








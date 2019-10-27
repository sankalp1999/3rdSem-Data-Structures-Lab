#include <iostream>
using namespace std;
int main()
{
    int row, col, nz ;
    cout << "Please enter the number of the rows." << endl;
    cin >> row ;
    cout << "Please enter the number of the columns." << endl;
    cin >> col ;
    cout << "Please enter the number of non-zero values." << endl;
    cin >> nz ;

    int rowv[nz], colv[nz], valuev[nz];
    for(int i = 0 ; i < nz ; i++)
    {
            cout << "Row " << i+1 << " " << endl;
            cin >> rowv[i];
            cout << "Column " << i+1 << " " << endl;
            cin >> colv[i];
            cout << "Value " << i+1 << " " << endl;
            cin >> valuev[i];
            cout << "-----------------"<< endl;
    }
    cout << "row" << "   " << "col" << "   " << "value" << endl;
    cout << row << "     " << col << "     " << nz << endl;
    for(int i = 0 ; i < nz ; i++)
    {
        cout << rowv[i] << "     " << colv[i] << "     " << valuev[i] << endl;
    }
    return 0;

}

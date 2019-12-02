#include <iostream>
using namespace std;
class sparse{
    private:
        int r, c, v ;
    public :
    sparse()
    {
        r = c = v = 0  ;
    }
    sparse(int row, int col, int val)
    {
        r = row;
        c = col;
        v = val;
    }
    void display(sparse s[])
    {
        cout << " \n row \t col \t value \n" ;

        for(int i = 0;  i <= s[0].v ; i++)
        {
            cout << s[i].r << "\t" << s[i].c << "\t" << s[i].v << endl;
        }
    }
    void convert(sparse s[], int mat[][6])
    {
        for(int i = 1; i <=  s[0].v; i++)

            {
                int rt = s[i].r;
                int ct = s[i].c;
                int vt = s[i].v;
                mat[rt][ct] = vt;
            }
            for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3 ; j++)
                {
                    cout << mat[i][j] << " " ;
                }cout << endl;
            }

    }
     void transpose(sparse s[] ,sparse temp[] )
    {

        temp[0].r = s[0].c ;
        temp[0].c = s[0].r ;
        temp[0].v = s[0].v ;
         int k = 1 ;
        for(int i = 0 ; i < s[0].c ; i++)
        {

            for(int j = 1 ; j <= s[0].v ; j++)
            {
                int rn = s[j].c;
                if (rn == i )
                {
                    temp[k].c = s[j].r ;
                    temp[k].r = s[j].c ;
                    temp[k].v = s[j].v ;
                    k++;
                }
            }
        }
        cout << " \n row \t col \t value \n" ;

            cout << temp[0].r << "\t" << temp[0].c << "\t" << temp[0].v << endl;
        for(int i = 1;  i <= s[0].v ; i++)
        {
            cout << temp[i].r << "\t" << temp[i].c << "\t" << temp[i].v << endl;
        }
    }
    void fast(sparse s[] ,sparse temp[])
    {
        cout << "Fast transpose" << endl;
        int i, rowterm[10];
        for(i = 0 ; i < s[0].c; i++)
        {
            rowterm[i] = 0;
        }
        for(i = 1 ; i <= s[0].v ; i++)
        {
            rowterm[s[i].c]++ ;// counting the number of columns.
        }
        int startpos[10];
        startpos[0] = 1 ;
        for(i = 1; i < s[0].c ; i++)
        {
            startpos[i] = startpos[i-1] + rowterm[i-1];
        }
        int k ;
        for(i = 1 ; i <= s[0].v ; i++)
        {
            k = startpos[s[i].c];
            temp[k].r = s[i].c ;
            temp[k].c = s[i].r  ;
            temp[k].v = s[i].v ;
            startpos[s[i].c]++;
        }
    }



};
int main()
{
    sparse s[20];
    sparse temp[20];
    int r, c, v ;
    cout << "Please enter the number of rows." << endl;
    cin >> r ;
    cout << "Please enter the number of columns." << endl;
    cin >> c ;
    cout << "Please enter the number of non-zero values." << endl;
    cin >> v;
    int mat[6][6] = {};
    int trans[6][6] = {};
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
   // s[0].convert(s, mat);
    s[0].transpose(s, temp);
    temp[0].display(temp);
}

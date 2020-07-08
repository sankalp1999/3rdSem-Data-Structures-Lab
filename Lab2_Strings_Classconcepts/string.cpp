#include <iostream>
#include <cstdio>

using namespace std;
void cat(char arr[], char arr2[])
{
        int k  ;
        for( k = 0; arr[k] != '\0';k++);
        for(int j = 0 ; arr2[j]!='\0';j++)
        {
            arr[k++] = arr2[j];
        }
        arr[k] = '\0';
}
int sl(char a[])
{
        int length = 0;
        for(int i = 0 ; a[i] != '\0';i++)
        {
            length++;
        }
    return length ;
}
int main()
{
    int length = 0 ;
    int i;// for length of the string
    cout << "Please enter the string for operation.";
    char str[200];
    gets(str);
    int pos,z, c, value, newl,subl, position;
    // case 5 variables
    int l5, l6, flag,j ,index;
    flag = 0 ;
    cout << "1. length of the string.\n";
    cout << "2. string concatenation.\n";
    cout << "3. string comparison.  \n";
    cout << "4. To insert a substring. \n";
    cout << "5. To delete a substring. \n";
    int input;
    cin >> input ;
    switch(input)
    {
    case 1 :

        length = sl(str);
        cout << "The length of the string is as :" << length << endl;
        break;
    case 2:
        char add[100];
        cout << "Please enter the string to concatenate.\n";
        fflush(stdin);
        gets(add);
        int k  ;
        k = sl(add);
        for(int j = 0 ; add[j]!='\0';j++)
        {
            str[k++] = add[j];
        }
        str[k] = '\0';
        cout << str  << endl ;
        break;

    case 3:
        cout << "Enter the string to compare with.\n";
        char comp[100];
        fflush(stdin);
        gets(comp);
        i = 0;
        // comparison code
        while(comp[i]!='\0' || str[i] != '\0')
        {
            if (comp[i] == str[i])
            {
                c = 0 ;
            }
            else if (comp[i] < str[i])
            {
                c = 1 ;
                break;
            }
            else if (comp[i] > str[i])
            {
                c = -1 ;
                break;
            }
                i++;
        }// end of the while loop
        if (c == 0)
        {
            if(comp[i] == '\0' && str[i] == '\0')
            {
                c = 0 ;
                cout << "Strings are equal." << endl;
            }
            else if (comp[i] != '\0')
            {
                c = 1 ;// s1 is greater
            }
            else if(str[i] != '\0')
            {
                c = 2;// s2 is greater
            }
        }
        if (c == 1)
        {
            cout << "String 1 is greater.\n";
        }
        else if (c == 2 || c == -1)
        {
            cout << "String 2 is greater.\n";
        }
        else if(c == 0)
        {
            cout << "The strings are equal in size.\n";
        }
        break ;
    case 4:
        // insert a substring
        char subs[100]; // substring
        cout << "Please enter the substring." << endl;
        fflush(stdin);
        gets(subs);
        char temp[300];
        cout << "Please enter the position where you want to insert the string.";
        cin >> pos;
        i = 0 ;
        length = sl(str);
        for(z = 0; z < pos ; z++)
        {
            temp[z] = str[i++];
        }
        temp[z] ='\0';
        cat(temp,subs); // concatenate
        newl = sl(temp) ;// new length
               for(z = newl ; z < newl + length - pos; z++)
        {
            temp[z] = str[i++];
        }
        temp[z] = '\0';
        cout << "The final string is : "<< temp << endl;
        break;
    case 5:
        cout << "Please enter substring.";
        fflush(stdin);
        gets(subs);// substring input
        int lenstr = sl(str);
        int lensub = sl(subs); // length of the substring

        for(i = 0 ; i < lenstr ; i++)
        {
            if  (str[i] == subs[0])
            {
                for( j = 0 ; j < lensub ; j++)
                {   cout << str[i] << " ";
                    if(str[i+j] == subs[j])
                    {
                        continue ;
                    }
                }
                    if (j == lensub )
                    {
                        cout << "Index has been found." << endl;
                        position = i ;
                        flag = 1 ;
                        break;
                    }
            }
        }
        if (flag == 0 )
        {
            cout << "The substring could not be found." << endl;
            break;
        }
        for(int k1 = 0 ; k1 < lensub ; k1++   )
    {
        for(int k2 = position ; k2 < lenstr; k2++)
        {
            str[k2] = str[k2+1];
        }
    }
    cout << str  << endl;

    }
return 0;
}

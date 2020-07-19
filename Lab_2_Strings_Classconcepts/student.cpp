#include <iostream>
using namespace std;
class Student
{
private:
        char name[100];
        int rno;
        char grade;
public:
        void read(Student[], int);
        void disp(Student[], int);
        void sort_info(Student[], int);
};
void Student::read(Student s1[], int i )
{
    cout << "Enter your name:" << endl;
    cin >> s1[i].name;
    cout << "Enter your roll no.:" << endl;
    cin >> s1[i].rno;
    cout << "Enter your grade " << endl;
    cin >> s1[i].grade;
}
void Student::disp(Student s1[], int i)
{
    cout << s1[i].rno << "\t" << s1[i].name << "\t\t"  << s1[i].grade;
}
void Student::sort_info(Student s1[], int n)
{
    Student flag;
    int i, j, key;
    for(i = 1 ; i < n; i++)
    {
        flag = s1[i];
        key = s1[i].rno;
        j = i - 1 ;
        while(s1[j].rno > key && j >= 0)
        {
            s1[j+1] = s1[j];
            j--;
        }
        s1[j+1] = flag;
    }
}
int main()
{
    int i, n;
    cout << "Enter the number of students." << endl;
    cin >> n ;
    Student s1[n];
    cout << "Enter the student details: " << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << "Student " << i+1 << " -->" << endl << endl;
        s1[i].read(s1,i);
    }
    cout << "Roll no \t tName \t Grade" << endl;
    for(i = 0 ; i  < n ; i++)
    {
        s1[i].disp(s1,i);
        cout << endl;
    }
    s1[i].sort_info(s1,n);
    cout << "Info after sorting: " << endl << endl;
    for(i = 0; i < n ;i++ )
    {
        s1[i].disp(s1,i);
        cout << endl;
    }
}

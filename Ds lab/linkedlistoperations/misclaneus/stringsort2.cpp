#include <iostream>
using namespace std;

class node2{
    char data;
    int freq;
    node2* next;
    public:
    void display();
    void insert_end(char x);
    void sort_list();
    int search_element(char b);
};
node2* first = NULL;
void node2::insert_end(char b)
{
if(first == NULL)
    {
        node2 *temp = new node2();

        temp->data = b;
        temp->next = NULL;
        first = temp;
    }
    else
    {
    node2 *temp;
    temp = first;
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << "hi" << endl;
    }
    node2* i = new node2();
    temp->next = i ;

    i->data = b ;
    i->next = NULL;
    }
}
void node2 :: display()
    {
        node2* i = first;
        while(i != NULL)
        {
        while(i->freq != 0 )
        {
        cout << i -> data << "  ----->  ";
        i->freq--;
        }

        i = i->next;
        }
        cout << "STOP" << endl;

    }

int node2::search_element(char x)
{
    node2* i ;
    i = first;
    int flag = 0 ;
    while(i!= NULL)
    {
        if(i->data == x)
        {
            i->freq++ ;
            flag = 1 ;
            return 0;
        }
        i= i->next;
    }
    if(flag == 0)
    {
        return 1;
    }
}
void node2 ::  sort_list()
{
    int temp ;
    cout << " ----- SORTED LIST ----  "<< endl;
    for(node2* i = first; i->next!= NULL; i = i->next)
    {
        for(node2* j = i->next ; j  != NULL ; j = j->next)
        {
            if(i->freq > j->freq)
            {

                temp = i->data;
                i->data = j->data;
                j->data= temp;
                //cout << i -> data << " " << j->data ;
            }
           // cout << endl;
        }
    }
}


int main()
{
    node2* list1 = new node2();
    char a[100];
    cin >> a ;
    for(int i = 0 ; a[i] !=  '\0'; i++)
    {
        if(list1->search_element(a[i]))
        {
            list1->insert_end(a[i]);
        }

    }
    list1->sort_list();
    list1->display();



}

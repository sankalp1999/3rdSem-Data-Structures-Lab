#include <iostream>
using namespace std;
class dll
{

    dll *prev;
    dll *next;
    int data;
public :
    void create(int ele);
    void insBefore();
    void delSpecific();
    void display();
    void delend();
    void insAfter();
    void reverse();
    void insert_specific(int ele, int pos);
};
dll* first1 = NULL;
class q
{
    dll* enq(dll* , int ele);
    int deq();
};
dll* q :: enq(dll* first1 ,int ele)
{
    dll* list1 = new dll();
    first1 = list1->create(ele);
    return first1;
}

void dll :: create(int ele)
{
    // to insert at the end of the list
    dll *t = new dll();
    t->data = ele;
    t->next = t->prev = NULL; // initialize both to NULL
    if(first == NULL)
    {
        first = t;

    }
    else
    {   dll* i ;
        for (i = first; i->next; i = i->next);

            i->next = t;
            t->prev = i;

    }
    display();
}
void dll :: insBefore()
{
    // before an existing element we have to add
    int x;
    int flag = 0; // element not found case
    cout << "Please enter the element before you want to insert the new node. " << endl;
    cin >> x;
    cout << "Enter new node data : ";
    dll *t = new dll();
    cin >> t->data;
    t->prev = t->next = NULL;
    if(first == NULL)
    {
        first = t;
    }
    else if(x == first->data)
    {
        t->next = first;        // t -> first
        first->prev = t;        // t <- first
        first = t; // now t is the first node of the linkedlist
        flag = 1;
    }
    else
    {
        for (dll *i = first; i; i = i->next)
        {
            if(i->data == x)
            {
                t->next = i;
                t->prev = i->prev;
                i->prev->next = t;
                i->prev = t;
                flag = 1;
                break;
            }
        }
    }

}
void dll::delSpecific()
{
    int x, flag = 0;
    dll *t;
    cout << "Enter the element to be deleted.";
    cin >> x;
    if(first == NULL)
    {
        cout << "List is empty. " << endl;
    }
    else if(first->data == x)
    {
        t = first;
        first = first->next;
        if(first)
        {
            first->prev = NULL;
        }
        delete (t);
        flag = 1;
    }
    else
    {
        for (dll *i = first; i ; i = i ->next)
        {
            if(i->data == x && i->next != NULL)
        {
                i->prev->next = i->next;
                i->next->prev = i->prev;
                delete (i);
                flag = 1;
        }   else if(i->data == x) // i has x and it is last node
            {
                i->prev->next = NULL; // just set second last node to null since
                                      // it has become the last node
                delete (i);
                flag = 1;
            }
        }
    }

}
void dll:: display()
{
    dll* t;
    t = first;
    if(t == NULL)
    {
        cout << "list is empty." << endl;
    }
    while (t != NULL)
    {
        cout << t->data << "---->" ;
        t = t->next;
    }
}
void dll::delend()
{
    dll *t;
    t = first;
    if(first == NULL)
    {
        cout << "The list is empty." << endl;
    }
    else if(t->next == NULL)
    {
        first = NULL;
        delete (t);
    }
    else{
    while(t -> next != NULL)
    {
        t = t->next; // exit on reaching the last node
    }
    t->prev->next = NULL;
    delete (t);
    }
}
void dll :: insAfter()
{
    dll *t = new dll();
    t->next = t->prev = NULL;
    int x;
    cout << "Please enter the element after which you want to insert." << endl;
    cin >> x;
    int ele;
    cout << "Enter the data." << endl;
    cin >> ele;
    t->data = ele;

    if(first == NULL)
    {
        cout << "list is empty." << endl;
        return ;
    }
    else if(first->data  == x)
    {
        t->next = first->next;
        first->next->prev = t;
        first->next = t;
        t->prev = first;

    }
    else
    {
        dll* i;
    for (i = first; i->next; i = i ->next)
    {
        if(i->data == x)
        {
            t->next = i->next;
            t->prev = i;
            i->next = t;
        }
    }
    if(i->next == NULL)
    {
        i->next = t;
        t->prev = i;
    }
    }
}
void dll :: reverse()
{
    dll* t ;
    dll* temp;
    temp = NULL;
    t = first;
    first->prev = NULL;
    while(t!= NULL)
    {
        temp = t->next;
        t->next = t->prev;
        t->prev = temp;
        if(t->prev == NULL)
        {
            first = t;
        }
        t = t->prev;
    }




}
void dll :: insert_specific(int ele, int pos )
{

    dll* t;
    t = first;
    dll* temp = new dll();
    temp->next = temp->prev = NULL;
    temp->data = ele;
    if(pos == 0)
    {

        temp->next = NULL;
        temp->prev = NULL;

    }
    else
    {
        if(pos == 1)
        {
            t->next = temp;
            temp->prev = t;

        }
        pos--;
        while(pos--)
        {
            t = t->next;
        }
        temp->next = t->next;
        temp->prev = t;
        t->next = temp;

    }


}
int main()
{
    int choice;
    int loc,elem;


    dll s;
    // enqueu


}

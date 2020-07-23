#include <iostream>
using namespace std;

class dll
{
    // one prev node, one data one next
    dll *prev;
    dll *next;
    int data;
    
public :
    void display(dll*);
    void create();
    dll* create(dll*, int ele);
    dll *merge(dll *, dll *);
    void traverse(dll* );
    dll* concatenate(dll *f1, dll *f2);
};
dll *first1 = NULL;
dll *first2 = NULL;
dll* dll :: concatenate(dll* f1, dll* f2)
{
    
    if(f1 == NULL)
    {
        f1 = f2;
        return f1;
    }
    else if(f2 == NULL)
    {
        return f1;
    }
    else
    {
        dll *i;
        for (i = f1; i->next; i = i -> next);
        i->next = f2;
        return f1;
    }
}
dll* dll ::create(dll *f, int ele)
{
    // to insert at the end of the list
    dll *t = new dll();
    // read data from the user
    t->next = t->prev = NULL; // initialize both to NULL
    t->data = ele;
    if (f == NULL)
    {
        f = t; // make f as t
    }
    else
    {
        dll *i;
        for (i = f; i->next; i = i->next);

            i->next = t;
            t->prev = i;
            // it will exit after setting in the last loop

    }
  //  display(f);
    return f;
}
dll* dll :: merge(dll* f1, dll* f2)
{
    dll *i = f1;
    dll *j = f2;
    dll *res = NULL;
    while(i != NULL && j != NULL)
    {
        if(i->data <= j->data)
        {
            res = create(res, i->data);
            i = i->next;
        }
        else
        {
            res = create(res, j->data);
            j = j->next;
        }
    }
    while(i)
    {
        res = create(res, i->data);
        i = i->next;
    }
    while(j)
    {
        res = create(res, j->data);
        j = j->next;
    }

}
void dll:: display(dll* t)
{
    dll *i;
    for (i = t; i; i = i ->next)
    {
        cout << i->data << " ";
    }
}
void dll :: traverse(dll* f)
{
    if(f == NULL)
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        dll* temp = f;
        while(temp != NULL)
        {
            cout << temp->data << " --> " ;
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    dll s;
    first1 = s.create(first1, 10);

    first1 = s.create(first1, 20);

    first1 =  s.create(first1, 30);
    first1 =  s.create(first1, 40);
    first2 = s.create(first2, 100);
    first2 = s.create(first2, 10000);
    cout << endl;
    s.traverse(first1);
    s.traverse(first2);
    cout << "After concatenation " << endl;
    first1 = s.concatenate(first1, first2);
    s.traverse(first1);
}

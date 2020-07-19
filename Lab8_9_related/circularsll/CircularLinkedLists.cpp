
#include <iostream>
using namespace std;

class cdll
{
    // one prev node, one data one next
    cdll *prev;
    cdll *next;
    int data;
    
public :
    
    void display(cdll*);
    cdll* create(cdll*, int ele);
    void traverse(cdll* );
    cdll* delspec(cdll *f, int ele);

};
cdll* head = NULL; // This creates a solid list

cdll* cdll :: delspec(cdll *f, int ele)
{
    cdll* t ;
    t = f;
    if(t->next == t)
    {
    f = NULL;
        
    delete(t);
        
    cout << "the list is empty." << endl;

    }
    else if(t->data == ele)
    {
        t->next->prev = t->prev;
        t->prev->next = t->next;
        f = t->next;
        delete(t);
    }
    else{

    t = t->next;
        
    while(t != f)
    {
        if(t->data == ele)
        {
        t->prev->next = t->next;
        delete(t);
        break;
        }

        t = t->next;
    }

    }
    return f;



}
cdll* cdll ::create(cdll *f, int ele)
{
    // to insert at the end of the list
    cdll *t = new cdll();

    // read data from the user
    t->next = t->prev = NULL; // initialize both to NULL
    t->data = ele;
    if (f == NULL)
    {
        f = t;
        t->next = f;

    }
    else
    {
        cdll *i;
        for (i = f; i->next != f; i = i->next);

            i->next = t;
            t->prev = i;
            t->next = f;
            f->prev = t; // for circular linkedlist
            // it will exit after setting in the last loop
    }
    return f;
}

void cdll:: display(cdll* t)
{
    cdll *i;
    if(t == NULL ){cout << "Empty list" << endl;return;}

    for (i = t; i->next != t; i = i ->next)
    {
        cout << i->data << " -> ";
    }
    cout << i->data << endl;
}

int main()
{
cdll s;
int flag = 1;
while (flag )
{
    int i;
    cout << "1.Insert an element. " << endl;
    cout << "2.Delete an element. " << endl;
    cout << "3.Display the list." << endl;
    cout << "4.Exit." << endl;
    cin >> i;
    int ele;
    switch(i)
    {
        case 1 :
            cout << "Enter the element to be inserted." << endl;
            
            cin >> ele;
            head = s.create(head, ele);
            break;
        case 2:
            cout << "Enter the element to be deleted." << endl;
            cin >> ele;
            head = s.delspec(head, ele);
            break;
        case 3 :
            s.display(head);
            break;
        case 4 :
            flag = 0;
        }
}
return 0;

}


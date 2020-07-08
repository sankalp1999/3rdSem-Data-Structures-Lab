

#include <iostream>
using namespace std;
// just make the head node both as the last as well as the first node.
class poly
{
    // one prev node, one data one next
    poly *prev;
    poly *next;
    int exp, coe;
public :
    void display(poly*);
    void create();
    poly* create(poly*, int coe, int exp);
    void traverse(poly* );
    poly* add(poly* p1, poly* p2);


};
poly* f1 = NULL;
poly* f2 = NULL;
poly* poly ::create(poly *f, int c, int e)
{
    // to insert at the end of the list
    poly *t = new poly();

    // read data from the user
    t->next = t->prev = NULL; // initialize both to NULL
    t->coe = c;
    t->exp = e;

    if (f == NULL)
    {
        f = t;
        t->next = f;

    }
    else
    {
        poly *i;
        for (i = f; i->next != f; i = i->next);

            i->next = t;
            t->prev = i;
            t->next = f;
            f->prev = t; // for circular linkedlist
            // it will exit after setting in the last loop
    }
    return f;
}


void poly:: display(poly* t)
{
    poly *i;
    if(t == NULL ){cout << "Empty list" << endl;return;}
    cout <<  t->coe << "  " << t->exp <<  " --> "; // first displaying first node and then further
    for (i = t->next; i != t; i = i ->next)
    {
        cout << i->coe << " " << i->exp  << " -> ";

    }
}
poly* poly :: add(poly* p1, poly* p2)
{
    poly *res = NULL;
    if(p1 == NULL){
        res = p1;
    }else if(p2 == NULL)
    {
        res = p2;
    }
    else{
        while(p1->next != p1 && p2->next != p2)
        {
            if(p1->exp > p2->exp)
            {
                res = create(res, p1->coe, p1->exp);
                p1 = p1->next;
            }
            else if(p1->exp < p2->exp)
            {
                res = create(res, p2->coe, p2->exp);
                p2 = p2->next;
            }
            else{
                res = create(res, p1->coe + p2->coe, p1->exp);
                p1 = p1->next;
                p2 = p2->next;

            }
        }
        }
        return res;
}
int main()
{
poly s;
poly s2;
poly s3;
f1 = s.create(f1, 5, 3);
f1 = s.create(f1,10, 2);
f1 = s.create(f1, 100, 1);
f1 = s2.create(f1, 5,0);
f2 = s2.create(f1, 25,4);
f2 = s2.create(f1, 55,3);
f2 = s2.create(f1, 115, 2);
f2 = s2.create(f1, 205,1);
f2 = s2.create(f1, 0,0);
f1 = s3.add(f1, f2);

s.display(f1);
cout << endl;
s2.display(f2);
s3.display(f1);
}

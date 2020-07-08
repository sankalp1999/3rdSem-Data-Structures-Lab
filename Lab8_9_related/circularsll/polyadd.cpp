

#include <iostream>
using namespace std;
// circular 
class poly
{
    // one prev poly, one data one next
    poly *prev;
    poly *next;
    int exp, coe;
public :
    void display(poly*);
    void create();
    poly* create(poly*, int coe, int exp);
    void traverse(poly* );
    poly* add(poly* p1, poly* p2);
    poly* mul(poly *p1, poly *p2);
    poly *simplify(poly *p1);



};
poly* f1 = NULL;
poly* f2 = NULL;

poly* poly :: mul(poly *p1, poly *p2)
{
poly *res = NULL;

for(poly *i = p1; i->next != p1; i = i->next)
{
    for(poly *j = p2; j->next != p2; j = j->next)
    {
        res = create(res, i->coe*j->coe, i->exp + j->exp);
    }

}

return res;

}
poly* poly :: simplify(poly* r)
{     if(!r)     return(NULL);
      poly *c,*res2=NULL;
     int i,coeSum=0,maxExp=r->exp;
    
    for (i = maxExp; i >= 0; i--)
    {
        
        
        for (c = r ; c != r->next; c = c->next)
        {
            if (c->exp == i)
                coeSum = coeSum + c->coe;
        }       
        for (c = r->next; c != r; c = c->next)
        {
            if (c->exp == i)
                coeSum = coeSum + c->coe;
        }

        if (coeSum != 0)
            res2 = create(res2, i, coeSum);
        coeSum = 0;
       }//for
return(res2);
}



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
    cout <<  t->coe << "  " << t->exp <<  " --> "; // first displaying first poly and then further
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
        poly* t1 = p1;
        poly* t2 = p2;

        while(p1->next != t1 && p2->next != t2)
        {   //cout << "kfk";
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
        while(p1  != t1)
        {
            res = create(res, p1->coe, p1->exp);
            p1 = p1->next;
        }
        while(p2  != t2)
        {
            res = create(res, p2->coe, p2->exp);
            p2 = p2->next;
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
f1 = s.create(f1, 5,0);
f2 = s2.create(f2, 25,4);
f2 = s2.create(f2, 55,3);
f2 = s2.create(f2, 115, 2);
f2 = s2.create(f2, 205,1);
f2 = s2.create(f2, 0,0);

s.display(f1);
cout << endl;
s2.display(f2);

f1 = s3.mul(f1, f2);
s3.display(f1);
f1 = s3.simplify(f1);

cout << endl;
cout << "After adding " << endl;
s3.display(f1);
}

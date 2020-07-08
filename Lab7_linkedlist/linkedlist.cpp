#include <iostream>
using namespace std;
class list1
{
    int data;
    list1* next;
    public :
        list1* create(list1*, int);

        list1* mergewithoutnewnode(list1*, list1*);
        list1* concatenate(list1*, list1*);
        void display(list1* f);
        list1* recursive(list1*, int data);
        list1* merge1(list1* f1, list1* f2);

};
list1* list1 :: merge1(list1 *f1, list1 *f2)
{
    list1 *i = f1, *j = f2;
    list1 *res = NULL;
    while( i != NULL && j != NULL)
    {
        if(i -> data <= j->data)
        {
            res = recursive(res, i->data);
            i = i -> next;
        }
        else
        {
            res = create(res, j->data);
            j = j -> next;
        }

    }
    while(i)
    {
        res = recursive(res, i->data);
        i = i -> next;
    }
    while(j)
    {
        res = recursive(res, j->data);
        j = j -> next;
    }
    display(res);
    return res;
}
list1* first1 = NULL;
list1* first2 = NULL;
list1* list1 :: recursive(list1* f, int ele)
{

    if( f == NULL){
        list1* node = new list1();
        node->data = ele;
        node->next = NULL;
        return node;
    }
    else
    {
    f->next = recursive(f->next, ele);
    }
    return f;


}
list1* list1:: create(list1*  f, int ele)
{
    list1 *t = new list1();

    t->data = ele;
    t->next = NULL;
    if(f == NULL)
    {
        f = t;
    }
    else
    {   list1* i;
        for(i = f ; i->next; i = i -> next);
        i->next = t ;
    }
    return f;
}
void list1::display(list1* f)
{
    if( f == NULL)
    {
    return ;
    }
    cout << f->data << " " ;
    display(f->next);
}

int main()
{
    list1 *a  = new list1();
    list1 *b = new list1();
    first1 = a->recursive(first1, 10);
    a->recursive(first1, 20);
    a->recursive(first1, 300000);
    first2 = b->recursive(first2, 200);
    b->recursive(first2, 2000);
    b->recursive(first2, 20000);
    list1 *c = new list1();
    c->merge1(first1, first2);
}

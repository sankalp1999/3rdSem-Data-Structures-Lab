
#include<iostream>
using namespace std;
class list
{
    int data;
    list* next;
public:
    int length(list*);
    list* insert_end(list*,int);
    list* merge_list(list*,list*);
    void display(list*);
};

list* f1=NULL,*f2=NULL;

int list::length(list* f)
{
    if(f==NULL)
        return 0;
    else
    {
        list* i;
        int c=0;
        for(i=f;i;i=i->next)
        c++;
        return c;
    }
}

list* list::insert_end(list* f,int ele)
{
    list* temp=new list;
    temp->data=ele;
    temp->next=NULL;
    if(f==NULL)
        f=temp;
    else
    {
        list* i;
        for(i=f;i->next;i=i->next);
        i->next=temp;
    }
    return f;
}

void list::display(list* f)
{
    if(f==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        for(list* i=f;i;i=i->next)
        {
            cout<<i->data<<" ";
        }
    }
}

list* list::merge_list(list* fa,list* fb)
{
    list* i=fa,*j=fb,*f3=NULL;

    while(i && j)
    {
        if(i->data <= j->data)
        {

            f3=insert_end(f3,i->data);
            i=i->next;

        }
        else
        {

            f3=insert_end(f3,j->data);
            j=j->next;

        }
    }
    while(i)
    {
        f3=insert_end(f3,i->data);
        i=i->next;
    }
    while(j)
    {
        f3=insert_end(f3,j->data);
        j=j->next;
    }
    return f3;
}

int main()
{
    list l;
    list* f3=NULL;
    f1=l.insert_end(f1,1);
    f1=l.insert_end(f1,3);
    f2=l.insert_end(f2,2);
    f1=l.insert_end(f1,4);
    f3=l.merge_list(f1,f2);
    l.display(f3);
}


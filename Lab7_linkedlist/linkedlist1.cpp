#include <iostream>
using namespace std;

class node{
    int data;
    node* next;
    public:
    void display();
    void insert_end(int x);
    void insert_before(int k, int data1);
    void insert_after(int k, int data1);
    void delete_specific(int k );


};
node* first = NULL;
void node :: display()
    {
        node* i = first;
        while(i != NULL)
        {
        cout << i -> data << "  ----->  ";
        i = i->next;
        }
        cout << "STOP" << endl;

    }
void node::insert_end(int x)
{
if(first == NULL)
    {
        node *temp = new node();

        temp->data = x;
        temp->next = NULL;
        first = temp;
    }
    else
    {
    node *temp;
    temp = first;
    while(temp->next != NULL)
    {
        temp = temp->next;
        cout << "hi" << endl;
    }
    node* i = new node();
    temp->next = i ;

    i->data = x ;
    i->next = NULL;
    }
}
void node::insert_before(int k, int data1)
{
    node* temp;

    if(first == NULL)
    {
        node* i = new node();

        i->next = NULL;
        i->data = data1;
        first = i ;
    }
    else if(first-> data == k)
    {
        node* i = new node();

        i->next = first;
        i->data = data1;
        first = i ;
    }
    else
    {
        while(temp->next->data != k)
    {
        temp = temp->next;
    }
    node *i = new node();
    i->next = temp->next;
    temp->next  = i  ;
    i->data = data1;
}
}
void node::insert_after(int k, int data1)
{
    node* temp;

    if(first == NULL)
    {
        node* i = new node();


        i->next = NULL;
        i->data = data1;
        first = i ;
    }
    else if(first-> data == k)
    {

        node* i = new node();
        temp = first;
        temp->next = first->next;
        temp->data = data1;
    }
    else
    {   temp = first;
        while(temp->data != k)
    {
        temp = temp->next;
    }
    node *i = new node();
    i->next = temp->next;

    temp->next  = i  ;
    i->data = data1;


}

}
void node::delete_specific(int k)
{
    node* temp = first;
    node* prev ;
    while(temp->data != k)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete(temp);
}

int main()
{
    node* list1 = new node();
    list1->insert_end(5);
    list1->insert_end(10);
    list1->insert_before(5,50);
    list1->insert_after(5,10000);
    list1->delete_specific(10000);
    list1->display();

}

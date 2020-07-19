/*
It's me from future:
This LL related code was taken from my friend God level friend Anutham.
He saved a few times when I was facing segmentation faults one-two days before lab.
I made the queue myself still.
The teacher can really cut marks if you don't make menu based program
*/

#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;
public:
    void insert_front();
    void insert_specific();
    void insert_end(int d);
    void insert_before_element();
    void insert_after_element();
    void display();
    int delete_end();
    void delete_repeated();  //assumes that the list is sorted
    void delete_alternate(); //deletes alternates excluding the first node
    int delete_front();
    void delete_specific();
    void sort_list();
    void insert_in_sorted_list();
    void reverse_list();
    int last();
};
node* first=NULL;//global variable
//Holds the address of the first node
int node:: last()
{
    node* temp;
    temp = first;
    if(first == NULL )
    {
        cout << "stack is empty" << endl;
        return 0;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}
void node::insert_end(int d)
{

    node* temp=new node;//default constructor
    
    temp->next=NULL;
    
    temp->data=d;
    
    if(first==NULL)
        first=temp;
    else
    {
        node *i;
        for(i=first;i->next!=NULL;i=i->next);
        i->next=temp;
    }
    //display();
}
void node::display()
{
    node* i=first;
    while(i!=NULL)
    {
       // cout<<"\nAddress :"<<i<<endl;
       // cout<<"Data :"<<i->data<<endl;
     //   cout<<"Address of next node :"<<i->next<<endl;
        cout << i->data << "----->";
        i=i->next;
    }
}
int node::delete_end()
{
    node *i,*prev;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return 0;
    }
    for(i=first;i->next!=NULL;i=i->next)
        prev=i;
    //i holds the address of the last node
    //prev holds the address of the second last node
    int c = i->data;
    delete(i);
    i=NULL;
    prev->next=NULL;
    return c ;
}

int node::delete_front()
{
    if(first==NULL)
    {
        cout<<"Empty list"<<endl;
        return 0;
    }
    node* i=first;
    
    first=(*i).next;
    
    int c = i->data;
    
    delete(i); // Not necessary but do this to avoid dangling pointers.
    
    i=NULL;
    
    return c ;
}

void node::delete_specific()
{
    if(first==NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    
    cout<<"Enter the data element to be deleted:";
    
    int x,flag=0;//flag=0 => element not found
    
    cin>>x;
    node* i=first,*prev;
    
    if(i->data==x)
    {
        first=i->next;
        
        delete(i);
        
        i=NULL;
        
        return;
    }
    for(;i;i=i->next)
    {
        if(i->data==x)
        {
            prev->next=i->next;
            delete(i);
            i=NULL;
            flag=1;
            break;
        }
        prev=i;//executed just before i=i->next
    }
    if(flag==0)
    {
        cout<<"Element not found!"<<endl;
        return;
    }
}

void node::insert_front()
{
    cout<<"Enter the element to be inserted:";
    int x;
    cin>>x;
    
    //node *i=first;
    node* temp=new node;
    temp->data=x;
    temp->next=first;
    first=temp;

}

void node::insert_specific()
{
    int x,pos,c=0,flag=0;
    cout<<"Enter the element to be inserted:";
    cin>>x;
    cout<<"Enter the position at which you want to insert this element:";
    cin>>pos;
    node* temp=new node;
    node* prev=first;
    temp->data=x;
    for(node* i=first;i;i=i->next)
    {
        c++;
        if(pos==c)
        {

            temp->next=i;
            if(c==1)
            first=temp;
            else
            prev->next=temp;
            flag=1;
            break;
        }
        prev=i;
    }
    if(!flag)
    {
        if(pos==c+1)
        {
            prev->next=temp;
            temp->next=NULL;
            return;
        }
        cout<<"Invalid position!\nTry again"<<endl;
        insert_specific();
    }
}
// This is only swapping values. 
// In end semester exam, they had asked to sort by swapping nodes. Hawa nikal gayi thi uss samay.
void node::sort_list()
{
    for(node* i=first;i->next;i=i->next)
    {
        for(node* j=i->next;j;j=j->next)
        {
            if(i->data > j->data)
            {
                int t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
}

void node::insert_in_sorted_list()
{
    int x;
    node *temp=new node;
    cout<<"Enter the element to be inserted:";
    cin>>x;
    temp->data=x;
    if(x<first->data)
    {
        temp->next=first;
        first=temp;
        return;
    }
    for(node* i=first;i->next;i=i->next)
    {
        if(x<i->next->data)
        {
            temp->next=i->next;
            i->next=temp;
            break;
        }
    }
}

void node::reverse_list()
{
    node* curr=NULL,*prev=NULL;
    while(first!=NULL)
    {
        curr=first;
        first=first->next;
        curr->next=prev;
        prev=curr;
    }
    first=curr;

}

void node::delete_repeated()
{
    int a=first->data;
    cout<<a;
    node* prev=first;
    for(node* i=first->next;i!=NULL;i=i->next)
    {
        if(i->data==a)
            prev->next=i->next;

        else
        {
            a=i->data;
            prev=i;
        }
    }

}

void node::insert_before_element()
{
    int flag=0;//target element not found
    cout<<"Enter the element to be inserted:";
    int x;
    cin>>x;
    cout<<"Enter the element before which you want to insert:";
    int pos;
    cin>>pos;
    node* temp=new node;
    temp->data=x;
    if(first->data==pos)
    {
        temp->next=first;
        first=temp;
        flag=1;
        return;
    }

    for(node* i=first;i->next;i=i->next)
    {
        if(i->next->data==pos)
        {
            temp->next=i->next;
            i->next=temp;
            flag=1;
            break;
        }

    }
    if(!(flag))
    {
        cout<<"Target element not found in the list!\nTry again..."<<endl;\
        insert_before_element();
    }
}

void node::insert_after_element()
{
    int flag=0;//target element not found
    cout<<"Enter the element to be inserted:";
    int x;
    cin>>x;
    cout<<"Enter the element after which you want to insert:";
    int pos;
    cin>>pos;
    node* temp=new node;
    temp->data=x;
    if(first->data==pos)
    {
        temp->next=first->next;
        first->next=temp;
        flag=1;
        return;
    }

    for(node* i=first;i;i=i->next)
    {
        if(i->data==pos)
        {
            temp->next=i->next;
            i->next=temp;
            flag=1;
            break;
        }

    }
    if(!(flag))
    {
        cout<<"Target element not found in the list!\nTry again..."<<endl;
        insert_after_element();
    }
}

void node::delete_alternate()//deletes the alternate nodes starting from the second node
{
    int c=0;
    node* prev=first;
    node* temp = first;

    while(temp != NULL)
    {
            prev = temp;
            temp = temp->next;
            if(temp == NULL){break;}
            prev->next = temp->next;
            temp = temp->next;
    }
}
class queue1
{   public :
    void push(int ele);
    int deque1();
    void display1();
    int topele();
};
void queue1 :: push(int ele)
{
    node* list2 ;
    list2->insert_end(ele);
}
int queue1::topele()
{
    node* list2;
    return list2->last();
}
int queue1 :: deque1()
{
    node* list2;
    list2->delete_front();
}
void queue1 :: display1()
{
    node* list2;
    list2->display();
}
int main()
{
    node list1;

    cout<<"\n\nChoose one of the following operations:\n";
    char c;
    queue1 s;

    do
    {

         switch(c)
         {
         case 'a':
            int a;
            cout << "Please enter the element to be pushed." << endl;
            cin >> a;
            s.push(a);
            break;
         case 'b':
            s.deque1();
            break;
         case 'c':
            s.display1();
            break;
         case 'd':
            cout << s.topele() << endl;



            break;
         }
         cout << "a. enqueue\nb. deque\nc. display\nd. topele" << endl;
         cin >> c;
    }while(c!='e');



}



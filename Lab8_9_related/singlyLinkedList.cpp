#include<iostream>
using namespace std;
class node
{
    int data;
    node* next;
public:
    void insert_front();
    void insert_specific();
    void insert_end();
    void insert_before_element();
    void insert_after_element();
    void display();
    void delete_end();
    void delete_repeated();//assumes that the list is sorted
    void delete_alternate();//deletes alternates excluding the first node
    void delete_front();
    void delete_specific();
    void sort_list();
    void insert_in_sorted_list();
    void reverse_list();
    void delete_multiple();
};
node* first=NULL;//global variable
//Holds the address of the first node


void node::delete_multiple()
{   node* z = first;
    while(z != NULL)
    {


    if(first==NULL)
    {
        cout<<"Empty list"<<endl;
       // return;
    }
    //cout<<"Enter the data element to be deleted:";
    int flag=0;//flag=0 => element not found
 //   cin>>x;
    node* i=first,*prev;
    if(i->data%3 == 0)
    {
        first=i->next;
        delete(i);
        i=NULL;
       // return;
    }
    for(;i;i=i->next)
    {
        if(i->data%3 == 0)
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
      //  return;
    }
    z = z->next;
    }
}
void node::insert_end()
{
    int d;
    cout<<"Enter node value:";
    cin>>d;
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
void node::delete_end()
{
    node *i,*prev;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    for(i=first;i->next!=NULL;i=i->next)
        prev=i;
    //i holds the address of the last node
    //prev holds the address of the second last node
    delete(i);
    i=NULL;
    prev->next=NULL;
}

void node::delete_front()
{
    if(first==NULL)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    node* i=first;
    first=(*i).next;
    delete(i);
    i=NULL;
}

void node::delete_specific()
{
    node* z ;
    z = first;
    while(z != NULL)
    {
    cout << "fjh" << endl;

    if(first==NULL)
    {
        cout<<"Empty list"<<endl;

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
      //  return;
    }
    z = z->next;
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

int main()
{
    node list1;

    cout<<"\n\nChoose one of the following operations:\n";
    char c;

    do
    {
         cout<<"\na)Insert an element before another element\nb)Insert an element after another element\nc)Delete a given element \nd)Sort the list\ne)Reverse the list\nf)Enter element in sorted list in order\ng)Delete every alternate node\nh)Insert at the end of the list\ni)Display\nj)Exit"<<endl;
         cin>>c;
         switch(c)
         {
         case 'a':
            list1.insert_before_element();
            break;
         case 'b':
            list1.insert_after_element();
            break;
         case 'c':
            list1.delete_multiple();
            break;
         case 'd':
            list1.sort_list();
            break;
         case 'e':
            list1.reverse_list();
            break;
         case 'f':
            list1.insert_in_sorted_list();
            break;
         case 'g':
            list1.delete_alternate();
            break;
         case 'h':
            list1.insert_end();
            break;
         case 'i':
            list1.display();
            break;
         case 'j':
            break;
         default:
            cout<<"Incorrect choice!!\nTry again"<<endl;
            break;
         }
    }while(c!='j');



}


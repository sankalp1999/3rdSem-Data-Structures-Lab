
#include<iostream>
using namespace std;
class node
{
    int data;
    node* next;
public:
    node* insert_end(node*,int);
    node* merge_list();
    void display(node*);
};

node* f1=NULL;
node* f2=NULL;

node* node::insert_end(node* first,int d)
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
    return first;

    //display();
}

void node::display(node* first)
{
    node* i=first;

    while(i!=NULL)
    {

        cout<<"Address :"<<i<<endl;
        cout<<"Data :"<<i->data<<endl;
        cout<<"Address of next node :"<<i->next<<endl;
        i=i->next;
    }
}

/*node* node::merge_list()
{
    node* c1=f1,*c2=f2,*c1n,*c2n;
    while(c1!=NULL && c2!=NULL)
    {
        while(c1->data < c2->data && c1->next!=NULL)
        {
            if(c1->next->data < c2->data)
                c1=c1->next;
            else
                break;
        }
        if(c2->data > c1->data)
        {
            c1n=c1->next;
            c2n=c2->next;
            c1->next=c2;
            if(c1n)
                c2->next=c1n;
                c2=c2n;
                c1=c1n;

        }
    }
    return c1;
}*/
node* node::merge_list()
{
	node *curra=f1;
	node *preva=NULL,*prevb=NULL;
	node *currb=f2;
	node *res=NULL; int pa=0,pb=0;

    if(f1->data<=f2->data)
    {
        pa=1;
        res=f1;
    }
    else
    {
         pb=1;
        res=f2;
    }

	while(curra!=NULL&&currb!=NULL)
	{
		if(curra->data<=currb->data)
		{
			if(pb==1)
            {
                prevb->next=curra;
                pa=1;
                pb=0;
            }
            preva=curra;
			curra=curra->next;
		}
		else //curra->data>currb->data
		{
            if(pa==1)
            {
                preva->next=currb;
               pa=0;
                pb=1;
            }
           prevb=currb;
        currb=currb->next;
		}
	}
	if(curra)
        prevb->next=curra;
    if(currb)
        preva->next=currb;
	//traverse(res);
	return(res);
}

int main()
{
    node n;
    f1=n.insert_end(f1,1);
    f1=n.insert_end(f1,3);
    f2=n.insert_end(f2,2);
    f2=n.insert_end(f2,4);
    f1=n.merge_list();
    //cout<<f1;
    n.display(f1);
}

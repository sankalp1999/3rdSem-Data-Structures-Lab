#include <iostream>
#include <cmath>
using namespace std;
class treenode
{
    treenode* rchild;
    treenode* lchild;
    int data;
    public :treenode *createBT();
    void inorder(treenode* p);
    void level_order(treenode *ptr);
    treenode *copy(treenode *ptr);
};
treenode *root = NULL;
treenode *treenode::copy(treenode *ptr)
{
    treenode *temp;
    if (ptr)
    {
        temp = new treenode;
        if (ptr->leftchild)
            temp->leftchild = copy(ptr->leftchild);
        if (ptr->rightchild)
            temp->rightchild = copy(ptr->rightchild);
        temp->data = ptr->data;
        return (temp);
    }
    return (NULL);
}
void treenode :: inorder(treenode* p)
{
    if(p)
    {
        inorder(p->lchild);
        cout << p->data << "\t";
        inorder(p->rchild);
    }
}
void treenode::level_order(treenode* ptr)
{
int front=-1;
int rear=-1;
treenode *Q[10];
if(!ptr) return;
Q[++rear]=ptr;
do
{
ptr=Q[++front];

cout << ptr->data << " ";
if (ptr->lchild)
    Q[++rear] = ptr->lchild;
if(ptr->rchild) Q[++rear]=ptr->rchild;

}while(front!=rear);
}

treenode* treenode :: createBT()
{
    // recursive function
    treenode* t;
    int x;

    cin >> x;
    if(x == -1)return NULL; // when no more depth, both l and r child are returnded as NULL
    else
    {
        t = new treenode();
        t->data = x;
        cout << "Enter the lchild of " << x << ":" ;
        t->lchild = createBT();
        cout << "Enter the rchild of" << x ;
        t->rchild = createBT();
        return t;
    }

}

int main()
{
    treenode *t;
    root = t->createBT();
    t->inorder(root);
    return 0;
}

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
   
};
treenode *root = NULL;

void treenode :: inorder(treenode* p)
{
    if(p)
    {
        inorder(p->lchild);
        cout << p->data << "\t";
        inorder(p->rchild);
    }
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

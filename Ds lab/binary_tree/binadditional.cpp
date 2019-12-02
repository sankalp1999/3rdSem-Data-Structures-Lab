#include <iostream>
#include <cmath>
using namespace std;
class treenode
{

    treenode* rchild;
    treenode* lchild;
    int data;
    public :
    treenode *createBT();
    treenode *insert(treenode*, int ele);
    void inorder(treenode* p);
    int depth(treenode* p);
    void it_preorder(treenode *p);
    void it_inorder(treenode *p);
    void it_postorder(treenode *p);
    void ancestors(int ele);
    treenode* parent(treenode *, int, treenode *);
    int LeafCount(treenode *p);
    int areMirror(treenode* , treenode* );
    int equal_tree(treenode*, treenode*);
};
treenode *root = NULL;
treenode* root2 = NULL;
int treenode ::  depth(treenode* p)
{
    if(!p){return 0;}
    int left = depth(p->lchild);
    int right = depth(p->rchild);
    return max(left,right) + 1;
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
int treenode ::  areMirror(treenode* a, treenode* b)
{

    if (a==NULL && b==NULL)
        return true;

    // If only one is empty
    if (a==NULL || b == NULL)
        return false;

    return  a->data == b->data &&
            areMirror(a->lchild, b->rchild) &&
            areMirror(a->rchild, b->lchild);
}
int treenode :: equal_tree(treenode* a, treenode* b)
{
    treenode* first = a;
    treenode* second = b;
    return ((!first && !second) || (first && second && (first->data == second->data) &&
                                    equal_tree(first->lchild, second->lchild) && equal_tree(first->rchild, second->rchild)));
}
void treenode :: it_preorder(treenode* p)
{
    treenode *s[10];
    treenode *ptr = p;
    int top = -1;
    do
    {
        for (; ptr; ptr = ptr->lchild)
        {
            cout << ptr->data << " ";
            s[++top] = ptr;
        }
        if(top>=0){
            ptr = s[top--];
        }
        else
        {
            break;
        }
        ptr = ptr->rchild;

    } while (1);


}
void treenode :: it_inorder(treenode* p)
{
    treenode *s[10];
    treenode *ptr = p;
    int top = -1;
    do
    {
        for (; ptr; ptr = ptr->lchild)
        {
            s[++top] = ptr;

        }
        if(top>=0){
            ptr = s[top--];
        }
        else
        {
            break;
        }

        cout << ptr->data << " ";
        ptr = ptr->rchild;

    } while (1);


}
void treenode :: it_postorder(treenode* r)
{
    if(r == NULL)
        return;
    else
    {
        treenode *s1[10], *s2[10];
        int t1 = -1;
        int t2 = -1;
        s1[++t1] = r;
        while(t1>= 0)
        {
            s2[++t2] = s1[t1--];
            if(s2[t2]->lchild){
                s1[++t1] = s2[t2]->lchild;
            }
            if(s2[t2]->rchild){
                s1[++t1] = s2[t2]->rchild;
            }
        }
        for (int i = t2; i >= 0;i--)
        {
            cout << s2[i]->data;
        }
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
treenode* treenode :: parent(treenode* curr, int ele, treenode* prev)
{
    if(curr != NULL)
    {
        parent(curr->lchild, ele, curr);
        if(ele == curr->data){
            cout << "\n parent : " << prev->data;
            return prev;
        }
        parent(curr->rchild, ele, curr);
    }
}
void treenode :: ancestors(int ele)
{
    treenode *p;
    p = parent(root, ele, root);
    while (1)
    {
        p = parent(root, p->data, root);
        if(p == root)
            break;
    }
}
int treenode :: LeafCount(treenode* p)
{
    if(p == NULL)
        return 0;
    if(p->lchild == NULL && p->rchild == NULL)
        return 1;
    else
        return LeafCount(p->lchild)+
            LeafCount(p->rchild);
}
int main()
{
    treenode *t;
    root = t->createBT();
    root2 = t->createBT();
    cout << "Inorder" << endl;
    t->it_inorder(root);
    cout << endl;
    cout << "Preorder" << endl;
    t->it_preorder(root);

    cout << endl;
    cout << "Postorder" << endl;
    t->it_postorder(root);
    cout << endl;
    cout << "Parent" << endl;
    t->parent(root, 2, root);
    t->parent(root, 3, root);
    //t->ancestors(4);
    int depth = t->depth(root);
    cout << "Depth : " << depth << endl;
    int s = t->LeafCount(root);
    cout << "Leaf count " << s << endl;
    t->equal_tree(root,root2);
    cout << "Mirror :" << t->areMirror(root, root2) << endl;
    cout <<"Equality : " << t->equal_tree(root, root2) << endl;

    return 0;
}

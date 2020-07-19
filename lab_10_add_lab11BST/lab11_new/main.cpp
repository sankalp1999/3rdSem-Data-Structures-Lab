#include <iostream>
using namespace std;

class bst
{
	bst *lchild;
	int data;
	bst *rchild;
public:
	bst(int ele=0)
	{
		lchild=NULL;
		rchild=NULL;
		data=ele;
	}
	void insert(int);
	void display(bst *root);
	bst* search(bst *p,int key);
	bst* deleteNode(bst* root, int key);
	bst* minimum_key(bst *ptr);
};

bst *root=NULL;

void bst::insert(int ele)
{
    bst *temp=new bst(ele);
    if(root==NULL){root=temp;return;}
    else
    {
        bst *curr=root,*prev=NULL;
    while(curr)
    {
    prev=curr;
    if(temp->data<curr->data)
        curr=curr->lchild;
    else if(temp->data>curr->data)
        curr=curr->rchild;
    else
        {cout<<"Insertion is not possible";return;}}
    if(temp->data>prev->data)
        prev->rchild=temp;
    else if(temp->data<prev->data)
        prev->lchild=temp;
}
return;
}

void bst::display(bst *p) //inorder rec
{
    if (p!=NULL)
    {
        display(p->lchild);
        cout<<p->data<<" ";
        display(p->rchild);
    }
}

bst* bst::search(bst *p,int key)
{
    if (p==NULL) return NULL;
    if(key == p->data) return p;
    if( key<p->data) return search(p->lchild,key);
    else
    return search(p->rchild,key);
}

bst* bst::minimum_key(bst *ptr)
{
    bst *curr = ptr;
    /* loop down to find the leftmost leaf */
  
    while (curr && curr->lchild != NULL)
        {curr = curr->lchild; }
    return curr;
}

bst* bst::deleteNode(bst* root, int key)
{
    if (root == NULL) return root;
    // Recursive calls for ancestors of node to be deleted
    if (key < root->data)
        {root->lchild = deleteNode(root->lchild, key);}
    else if (key > root->data)
        {root->rchild = deleteNode(root->rchild, key);}
    // We reach here when root is the node to be deleted
    // If one of the children is empty
    else{
        if (root->lchild == NULL)
        { bst* temp = root->rchild; delete root; return temp; }
        else if (root->rchild == NULL)
        { bst* temp = root->lchild; delete root; return temp; }
        // If both children exist
        else if(root->lchild && root->rchild)
        {
            bst *temp=minimum_key(root->rchild);
        // Copy the inorder successor's content to this node
            root->data = temp->data;
        // Delete the inorder successor
            root->rchild = deleteNode(root->rchild, temp->data);
        } }
    return root;
}


int main()
{
    bst b;
    bst *temp;

    int t;
    for(int i=1;i<=6;i++)
    {
    cout<<"enter element to insert:";
    cin>>t;
    b.insert(t);
    }
    b.display(root);

    int p;
    cout<<"\nenter key to search:";
    cin>>p;
    temp=b.search(root,p);
    if (temp==NULL) cout<<"\nkey not found";
    else cout<<"\nkey found";

    cout<<"\nenter key to delete:";
    cin>>p;
    root=b.deleteNode(root,p);
    b.display(root);
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
class exp_tree
{
public:
    exp_tree *left;
    char data;
    exp_tree *right;
    exp_tree() {}
    exp_tree(char ele)
    {
        data = ele;
        left = NULL;
        right = NULL;
    }
    exp_tree *create(char);
    void inorder(exp_tree *);
};
exp_tree *root = NULL;
exp_tree *exp_tree::create(char ele)
{
    exp_tree *temp = new exp_tree(ele);
    return temp;
}
void exp_tree::inorder(exp_tree *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}
int main()
{
char postfix[20];
int i=0,top=-1;

exp_tree *stack[10],obj;
cout<<"Enter the postfix expression: "; cin>>postfix;
while(i<strlen(postfix))
{
if(isalpha(postfix[i]))
stack[++top]=obj.create(postfix[i]);

else
{
root=obj.create(postfix[i]);
root->right=stack[top--];
root->left=stack[top--];
stack[++top]=root;
}
i++;
}
obj.inorder(root);

}

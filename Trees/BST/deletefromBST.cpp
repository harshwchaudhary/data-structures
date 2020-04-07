#include<iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

struct node * Rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);
    return p;
}

void Inorder(struct node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int Height(struct node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y ? x+1 : y+1;
}

struct node *Inpre(struct node *p)
{
    while(p && p->rchild!=NULL)
        p = p->rchild;
    return p;
}

struct node *Insucc(struct node *p)
{
    while(p && p->lchild!=NULL)
        p = p->lchild;
    return p;
}

struct node * Delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild==NULL)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data); 
        }
        else
        {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    struct node *temp;

    root = Rinsert(root,50);
    Rinsert(root,10);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,30);

    Inorder(root);
    cout<<"\n";
    Delete(root,50);
    cout<<"\n"; 
    cout<<"After deletion \n";
    Inorder(root);
    cout<<endl;

}
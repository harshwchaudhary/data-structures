#include<iostream>

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root=NULL;

int NodeHeight(struct node *p)
{
    int hl,hr;
    hl= p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl>hr ? hl+1:hr+1;
}

int BalFactor(struct node *p)
{
    int hl,hr;
    hl= p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl-hr;
}

struct node * LLRotate(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}

struct node LRRotate(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root==p)
        root = plr;
    return plr;
}


struct node * Rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t = new node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);
    p->height = NodeHeight(p);
    if(BalFactor(p)==2 && BalFactor(p->lchild)==1)
        return LLRotate(p);
    else if(BalFactor(p)==2 && BalFactor(p->lchild)==-1)
        return LRRotate(p);
    // else if(BalFactor(p)==-2 && BalFactor(p->rchild)==-1)
    //     return RRRotate(p);
    // else if(BalFactor(p)==-2 && BalFactor(p->lchild)==1)
    //     return RLRotate(p);

    return p;
}

int main()
{
    root = Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,2);

    return 0;
}
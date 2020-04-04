#include<iostream>
#include<stdlib.h>
#include "Queue.h"

struct node *root=NULL;

void Treecreate()
{
    struct node *p,*t;
    int x;
    struct queue q;
    create(&q,100);

    cout<<"Enter root value: \n";
    cin>>x;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enque(&q,root);

    while(!isEmpty(q))
    {
        p = deque(&q);
        cout<<"Enter left child value: "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enque(&q,t);
        }
        cout<<"Enter right child value: "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enque(&q,t);
        }
    }
}

void preorder(struct node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    Treecreate();
    preorder(root);
    return 0;
}
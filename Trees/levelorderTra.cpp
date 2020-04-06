#include<iostream>
#include<stdlib.h>
#include "Queue.h"
using namespace std;

struct node *root = NULL;

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

void LevelOrder(struct node *root)
{
    struct queue q;
    create(&q,100);

    cout<<root->data<<" ";;
    enque(&q,root);

    while(!isEmpty(q))
    {
        root = deque(&q);
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            enque(&q,root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            enque(&q,root->rchild);
        }
    }
}

int main()
{
    Treecreate();
    LevelOrder(root);
    return 0;
}
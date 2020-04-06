#include<iostream>
#include<stdlib.h>
#include "Queue.h"
using namespace std;

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

int count(struct node *root)
{
    if(root)
        return count(root->lchild) + count(root->rchild)+1;
    else
        return 0;
}

int height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    Treecreate();
    cout<<"Number of nodes are: "<<count(root);
    cout<<endl;
    cout<<"Height of tree is : "<<height(root);
    cout<<endl;
    return 0;
}
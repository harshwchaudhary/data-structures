#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;    //One pointer to point to an array and other to struct node
};

void create(struct queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node **)malloc(q->size*sizeof(struct node *));
}

void enque(struct queue *q,struct node *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is full\n";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct node *deque(struct queue *q)
{
    struct node* x = NULL;
    if(q->front == q->rear)
        cout<<"Queue is empty\n";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q)
{
    return q.front == q.rear;
}
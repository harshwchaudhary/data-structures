#include<iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q,int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void enqueue(struct queue *q,int x)
{
    if(q->rear == q->size - 1)
        cout<<"Queue is full";
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        cout<<"Queue is empty\n";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct queue q){

    for(int i=q.front+1;i<=q.rear;i++)
        cout<<q.Q[i]<<" ";
    cout<<"\n";
}

int main()
{
    struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);
    cout<<"\n";
    cout<<"Deleted number is : "<<dequeue(&q);
    cout<<endl;
    display(q);
    return 0;
}
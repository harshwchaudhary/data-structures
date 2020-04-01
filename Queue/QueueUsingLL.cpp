#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t;
    t = new node;
    if(t==NULL)
        cout<<"Queue is full\n";
    else
    {
        t->data = x;
        t->next = NULL;
        if(front==NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct node *t;
    if(front==NULL)
        cout<<"Queue is empty\n";
    else
    {
        t = front;
        front=front->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    struct node *p=front;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);

    display();
    cout<<endl;
    cout<<"Dequeued item is : "<<dequeue();
    display();
    return 0;
}
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t;
    t = new node;
    if(t==NULL)
        cout<<"Stack is full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }        
}
int pop()
{
    struct node *t;
    int x = -1;
    if(top==NULL)
        cout<<"Stack is empty";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;      
}

void display()
{
    struct node *p;
    p = top;
    while(p)
    {
        cout<<p->data<<"\n";
        p = p->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();
    cout<<endl;
    pop();
    display();
    return 0;
}
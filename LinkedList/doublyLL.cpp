#include<iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;

void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"\n";
        p=p->next;
    }
    cout<<"\n";
}
int Length(struct node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void create(int arr[],int n)
{
    int i;
    struct node *t,*last;
    
    first = new node;
    first->data = arr[0];
    first->prev = first->next=NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
int main()
{
        int A[] = {10,20,30,40,50};
        create(A,5);
        cout<<"Length is : "<<Length(first);
        display(first);
        return 0;
}
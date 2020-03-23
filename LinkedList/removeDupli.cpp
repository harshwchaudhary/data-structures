#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first = NULL;

void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void create(int arr[], int n)
{
    int i;
    struct node *t,*last;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void removeDupli(struct node *p)
{
    struct node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
int main()
{
    int A[] = {10,20,20,20,30,40,50};
    create(A,7);
    display(first);
    cout<<"\n";
    removeDupli(first);
    display(first);
    return 0;
}

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL,*second=NULL,*third=NULL;

void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void create(int arr[],int n)
{
    int i;
    struct node *t,*last;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last =first;
    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    } 
}
void create2(int arr[],int n)
{
    int i;
    struct node *t,*last;
    second = new node;
    second->data = arr[0];
    second->next = NULL;
    last =second;
    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    } 
}
void concat(struct node *p,struct node *q)
{
    third = p;
    while(p->next)
    {
        p = p->next;
    }
    p->next=q;
}
int main()
{
    int A[] = {50,40,10,30,20};
    int B[] = {1,2,3,4,5};
    create(A,5);
    create2(B,5);
    concat(first,second);
    display(third);
    return 0;
}
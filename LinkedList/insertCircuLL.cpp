#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*head;

void display(struct node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    
}
int Length(struct node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p!=head);
    return len;
    
}
void Insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index < 0 || index > Length(head))
        return ;
    if(index==0)
    {
        t = new node;
        t->data = x;
        if(head==NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next!=head)
                p->next = t;
            t->next = head;
            head = t; 
        }
        
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t = new node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
    
    
}
void create(int A[], int n)
{
    int i;
    struct node *t,*last;
    head = new node;
    head->data = A[0];
    head->next = head;
    last = head;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    Insert(head,2,10);
    display(head);
    return 0;
}
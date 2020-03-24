#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void Display(struct node *p)
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
int Delete(struct node *p,int index)
{
    struct node *q;
    int i,x;
    if(index<0 || index > Length(head))
        return -1;
    if(index==1)
    {
        while(p->next!=head) p=p->next;
        x = head->data;
        if(head==p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
        
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q = p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
    return x;
}
void create(int arr[],int n)
{
    int i;
    struct node *t,*last;
    head = new node;
    head->data = arr[0];
    head->next = head;
    last = head;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    Delete(head,1);
    Display(head);
    return 0;
}
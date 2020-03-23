#include<iostream>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*head;

void Display(struct node *h)
{
    do
    {
        cout<<h->data<<" ";
        h = h->next;
    } while(h!=head);
    cout<<"\n";
}

void RDisplay(struct node *h)
{
    static int flag = 0;
    if(h!=head || flag==0)
    {
        flag = 1;
        cout<<h->data<<" ";
        cout<< " ";
        RDisplay(h->next);
    }
    flag = 0;
}

void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    head = new node;
    head->data= A[0];
    head->next = head; // now circular
    last = head;
    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = A[i];
        t->next = last->next; // coz its circular we can't use NULL
        last ->next = t;
        last = t;
    }
}
int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    //Display(head);
    RDisplay(head);
    return 0;
}
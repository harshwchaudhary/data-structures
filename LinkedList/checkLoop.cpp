#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[],int n)
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
bool isloop(struct node *f)
{
   struct node *p,*q;
   p =  q = f;
   do
   {
      p = p->next;
      q = q->next;
      q = q ? q->next : q;
   } while (p && q && p!=q);
   if(p==q)
    return true;
   else
   {
       return false;
   }
     
}

int main()
{
    struct node *t1,*t2;
    int A[] = {10,20,30,40,50};
    create(A,5);
   // t1 = first->next->next;
   // t2 = first->next->next->next->next; 
   // t2->next = t1;
    if(isloop(first))
    {
        cout<<"There's a loop\n";
    }
    else
    {
        cout<<"NO LOOP\n";
    }
    
    return 0;
}
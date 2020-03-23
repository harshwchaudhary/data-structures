#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
}*first=NULL;

bool isSorted(struct node *p)
{
  int x= -65536;
  while(p)
  {
    if(p->data < x)
      return false;
    x = p->data;
    p = p->next;
  }
  return true;
}

void display(struct node *p)
{
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p = p->next;
  }
}

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

int main()
{
  int A[] = {10,20,15,40,50};
  create(A,5);
  display(first);
  bool x = isSorted(first);
  if(x==true)
    cout<<"Sorted"<<endl;
  else
    cout<<"Not Sorted"<<endl;
  return 0;
}

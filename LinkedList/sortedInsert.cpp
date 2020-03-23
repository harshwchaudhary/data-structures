#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
  int data;
  struct node *next;
}*first = NULL;

void SortedInsert(struct node *p,int x){
  struct node *t,*q=NULL;
  t = (struct node *)malloc(sizeof(struct node));
  t->data = x;
  t->next = NULL;
  if(first==NULL)
    first = t;
  else{
    while(p && p->data < x){
      q = p;
      p = p->next;
    }
    if(p==first){
      t->next = first;
      first = t;
    }
    else{
      t -> next = q->next;
      q->next =t;
    }
  }
}

void create(int arr[],int n){
  int i;
  struct node *t,*last;
  first = (struct node *)malloc(sizeof(struct node));
  first->data = arr[0];
  first->next = NULL;
  last = first;
  for(i=1;i<n;i++){
      t = (struct node *)malloc(sizeof(struct node));
      t->data = arr[i];
      t->next = NULL;
      last->next = t;
      last = t;
  }
}
void display(struct node *p){
  while(p){
    cout<<p->data<<" ";
    p=p->next;
  }
}

int main()
{
  int a[] = {10,20,30,40,50};
  create(a,5);

  SortedInsert(first,35);
  display(first);
  return 0;
}

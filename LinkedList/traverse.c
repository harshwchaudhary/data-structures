#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*first=NULL;

void create(int a[],int n){
  int i;
  struct node *t,*last;
  first = (struct node *)malloc(sizeof(struct node));
  first->data = a[0];
  first->next = NULL;
  last = first;
  for(i=1;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
void display(struct node *p){
  while(p!=NULL){
    printf("%d ",p->data);
    p = p->next;
  }
}
void recurDisplay(struct node *p){
  if(p!=NULL){
    printf("%d ",p->data);
    recurDisplay(p->next);

  }
}
int main()
{
  int n,i;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
      scanf("%d ",&a[i]);
  }
  create(a,n);
  //display(first);
  recurDisplay(first);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
  int data;
  struct node *next;
}*first= NULL;

void create(int arr[],int n){
  int i;
  struct node *t,*last;
  first = (struct node *)malloc(sizeof(struct node));
  first->data = arr[0];
  first->next = NULL;
  last = first;
  for(i=0;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
int max(struct node *p){
  int x=0;
  if(p==0)
    return INT_MIN;
  else{
    x = max(p->next);
    if(x>p->data)
    return x;
    else
    return p->data;
  }
}

int main(){
  int a[] = {3,5,7,1,10,2,17};
  create(a,7);
  printf("Max is : %d",max(first));
  return 0;
}

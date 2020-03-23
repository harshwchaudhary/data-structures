#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*first = NULL;

void display(struct node *p){
  while(p){
    printf("%d \t\n",p->data);
    p=p->next;
  }
}
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
int count(struct node *p){
  int c = 0;
  while(p){
    c+=1;
    p=p->next;
  }
  return c;
}
int sum(struct node *p){
  int su = 0;
  while(p){
    su  = su + p->data;
    p = p->next;
  }
  return su;
}

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d ",&a[i]);
  }
  create(a,n);
  display(first);
  int cnt  = count(first);
  printf("Number of nodes are : %d\n",cnt);
  int nsum = sum(first);
  printf("Sum of nodes are : %d\n",nsum);
  return 0;
}

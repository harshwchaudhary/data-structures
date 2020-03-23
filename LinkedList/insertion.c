#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*first = NULL;

int count(struct node *p){
  int c = 0;
  while(p){
    c+=1;
    p=p->next;
  }
  return c;
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
void insert(struct node *p,int pos,int x){
  struct node *t;
  int i;
  if(pos==0){
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = first;
    first = t;
  }
  else if(pos < 0 || pos > count(p)){
    return ;
  }
  else{
    p = first;
    for(i =0 ;i<pos-1 && p ;i++){
      p = p->next;
    }
    if(p){
      t = (struct node *)malloc(sizeof(struct node));
      t->data =x;
      t->next = p->next;
      p->next = t;
    }
  }
}
void display(struct node *p){
  while(p){
    printf("%d ",p->data);
    p = p->next;
  }
}

int main()
{
  int a[] = {3,5,7,10,25,8,32,2};
  int pos,val;
  create(a,8);
  display(first);
  printf("\n");
  printf("Enter position and value : ");
  scanf("%d %d",&pos,&val);
  insert(first,pos,val);
  display(first);
  return 0;
}

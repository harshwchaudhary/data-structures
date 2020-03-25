#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first = NULL;

void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int Length(struct node *p)
{
	int len=0;
	while(p)
	{
		len++;
		p=p->next;
	}
	return len; 
}

void create(int arr[],int n)
{
	int i;
	struct node *t,*last;
	first = new node;
	first->data = arr[0];
	first->prev = first->next = NULL;
	last = first;
	for(i=1;i<n;i++)
	{
		t = new node;
		t->data = arr[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}
void Insert(struct node *p,int index,int x)
{
	struct node *t;
	int i;
	if(index < 0 || index > Length(p))
		return ;
	if(index == 0)
	{
		t = new node;
		t->data = x ;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t = new node;
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if(p->next)
		{
			p->next->prev = t;
			p->next =t;
		}
	}
}
int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	Insert(first,2,25);
	display(first);
	return 0;
}
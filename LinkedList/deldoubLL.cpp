#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first = NULL;

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
		last =t ;
	}
}
void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}
int Length(struct node *p)
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}

int Delete(struct node *p,int index)
{
	struct node *q;
	int x=-1,i;
	if(index < 1 || index > Length(p))
		return -1;
	if(index==1)
	{
		first = first->next;
		if(first)
		{
			first->prev = NULL; 
		}
		x = p->data;
		delete p;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;
		x = p->data;
		delete p;
	}
}

int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	Delete(first,1);
	display(first);
	return 0;
}


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
		last = t;
	}
}
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
void reverse(struct node *p)
{
	struct node *temp;
	while(p)
	{
			temp = p->next;
			p->next = p->prev;
			p->prev = temp;
			p=p->prev;
			if(p!=NULL &&p->next==NULL)
				first = p;
	}
}
int main()
{
	int A[] = {10,20,30,40,50};
	create(A,5);
	display(first);
	cout<<"\n";
	reverse(first);
	cout<<"\n";
	display(first);
	return 0;
}
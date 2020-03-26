#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<"\n";
}
void findMid(struct node *p)
{
	struct node *q;
	p = q = first; 
	while(q)
	{
		q = q->next;
		if(q)
			q= q->next;
		if(q)
			p = p->next;
	}
	cout<<"Mid element is : "<<p->data<<endl;;
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
	int A[] = {10,20,30,40,50};
	create(A,5);
	display(first);
	findMid(first);
	return 0;
}
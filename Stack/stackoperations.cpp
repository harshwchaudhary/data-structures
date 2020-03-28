#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack
{
	int size;
	int top;
	int *S;
};

void create(struct stack *st)
{
	cout<<"Enter size of stack";
	cin>>st->size;
	st->top = -1;
	st->S = (int *)malloc(st->size *sizeof(int));
}

void display(struct stack st)
{
	for(int i=st.top;i>=0;i--)
		cout<<st.S[i]<<"\n";
}

void push(struct stack *st,int x)
{
	 if(st->top == st->size-1)
	 	cout<<"Stack Overflow\n";
	 else
	 {
	 	st->top++;
	 	st->S[st->top] = x;
	 }
}

int pop(struct stack *st)
{
	int x = -1;
	if(st->top == -1)
		cout<<"Stack Underflow";
	else
	{
		x = st->S[st->top];
		st->top--;
	}
	return x;
}
int isEmpty(struct stack st)
{
	if(st.top==-1)
		return 1;
	else 
		return 0;
}
int isFull(struct stack st)
{
	if(st.top==st.size-1)
		return 1;
	else
		return 0;			
}

int peek(struct stack st,int index)
{
	int x = -1;
	if(st.top-index+1 < 0)
		cout<<"Invalid Index";
	else
	{
		x = st.S[st.top-index+1];
	}
	return x;
}

int stackTop(struct stack st)
{
	if(st.top==-1)
		return -1;
	else
		return st.S[st.top];
}


int main()
{
	struct stack st;
	create(&st);
	push(&st,10);
	push(&st,20);
	push(&st,30);
	push(&st,40);
	push(&st,50);

	cout<<"The asked peek element is : "<<peek(st,3)<<"\n";
	display(st);

	// pop(&st);
	// display(st);
	// isEmpty(&st);
	// isFull(&st);
	// peek(st,3);
	// stackTop(st);
	
	return 0;
}
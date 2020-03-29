#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char x)
{
    struct node *t;
    t = new node;
    if(t==NULL)
        cout<<"Stack is full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct node *t;
    char x = -1;
    if(top==NULL)
        cout<<"Stack is empty";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    struct node *p;
    p = top;
    while(p)
    {
        cout<<p->data<<"\n";
        p = p->next;
    }
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL) //if stack is empty
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp;
    int len;
    cin.getline(exp,20);
    if(isBalanced(exp))
        cout<<"Balanced\n";
    else
        cout<<"Not Balanced\n";
    return 0;
}
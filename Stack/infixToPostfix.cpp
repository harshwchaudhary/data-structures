#include<iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(int x)
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
    int x = - 1;
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

int pre(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}

int isEmpty()
{
    return top ? 0 : 1;
}

int stackTop()
{
    if(top)
        return top->data;
    return -1;
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
char * intoPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+2];

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i])> pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while(top!=NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = intoPost(infix);

    cout<<postfix<<"\n";

    return 0;
}
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*top = NULL;

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

int pop()
{
    struct node *t;
    int x = -1;
    t = new node;
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

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}

int Eval(char *postfix)
{
    int i = 0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2 = pop(); x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1+x2; break;
                case '-': r = x1-x2; break;
                case '*': r = x1*x2; break;
                case '/': r = x1/x2; break;
            }
            push(r);
        }
    }
    return  top->data;
}


int main()
{
    char *postfix = "234*+82/-";
    cout<<"Result is : "<<Eval(postfix);
    cout<<"\n";
    return 0;
}
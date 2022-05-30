#include<bits/stdc++.h>
using namespace std;

char stk[100];
int top = -1;

void push(char item)
{
    if(top != 100)
        stk[++top]=item;
    else cout<<"Stack Overflow";
}

char pop()
{
    if(top != -1)
        return stk[top--];
    else cout<<"Stack Underflow";
}

bool isEmpty()
{
    if(top == -1)
        return true;
    else return false;
}

int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
	else return 0;
}

string revString(string r)
{
    int i,j;
    string p;
    int len = r.length();
    for(i = len-1; i > -1; i--)
    {
        p=p+r[i];
    }
    for(int i=0;i<p.length();i++)
        if(p[i]=='(') p[i] = ')';
        else if(p[i]==')') p[i]='(';
    return p;
}

void infixtoprefix(string q)
{
    string p;
    q = revString(q);
    int i = 0;
    push('(');
    q = q + ')';
    while(!isEmpty())
    {
        if(q[i] == '(')
            push(q[i]);
        else if(q[i] == ')')
        {
            while(stk[top] != '(')
            {
                p = p + stk[top];
                pop();
            }
            pop();
        }
        else if(precedence(q[i]) != 0)
        {
            while(precedence(q[i]) <= precedence(stk[top-1]))
            {
                p = p + stk[top];
                pop();
            }
            push(q[i]);
        }

        else
            p=p+q[i];
        i++;
    }
    p = revString(p);
    cout<<p<<'\n';
}

int main()
{
    string Q;
    cin>>Q;
    infixtoprefix(Q);
    return 0;
}

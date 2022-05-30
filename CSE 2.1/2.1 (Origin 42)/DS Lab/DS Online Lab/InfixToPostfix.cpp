#include<bits/stdc++.h>
using namespace std;

char stk[100];
int st_top=0;

void push(char item)
{
    if(st_top!=100){
        stk[st_top] = item;
        st_top++;
    }
    else cout<<"Stack Overflow";
}

char pop()
{
    if(st_top!=0){
        st_top--;
        return stk[st_top];
    }
    else cout<<"Stack Underflow";
}

bool isEmpty()
{
    if(st_top==0)
        return 1;
    else return 0;
}

char top()
{
    if(st_top!=0)
        return stk[st_top-1];
    else cout<<"Stack is Empty";
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

int main()
{
    string q;
    int i=0;
    cin>>q;
    q = q + ')';
    push('(');
    while(!isEmpty())
    {

        if(q[i]=='(')
            push(q[i]);
        else if(q[i]==')')
        {
            while(top()!='(')
            {
                cout<<top();
                pop();
            }
            pop();
        }
        else if(precedence(q[i])!=0)
        {
            while(precedence(q[i])<=precedence(top()))
            {
                cout<<top();
                pop();
            }
            push(q[i]);
        }

        else cout<<q[i];
        i++;
    }
}


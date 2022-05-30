#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int a;
    char from,aux,to;
    Stack(int p,char q,char r,char s){
        a=p;
        from=q;
        aux=r;
        to=s;
    }
    Stack(){

    };
};
Stack stk[100];

int topp=0;

void push(int p,char q,char r,char s)
{
    if(topp!=100)
    {
        stk[topp].a=p;
        stk[topp].from=q;
        stk[topp].aux=r;
        stk[topp].to=s;
        topp++;
    }
    else printf("The stack is overflowing");
}

void push(Stack c)
{
    if(topp!=100)
        stk[topp++]=c;
    else printf("The stack is overflowing");
}

Stack pop()
{
    if(topp!=0)
        return stk[--topp];
    else printf("The stack is underflowing");
}

bool isEmpty()
{
    if(topp==0) return 1;
    else return 0;
}

Stack top()
{
    if(topp!=0) return stk[topp-1];
    else printf("The stack is empty");
}

void moves(int a,char from,char aux,char to)
{
    Stack temp(a,from,aux,to);
    push(temp);
    while(!isEmpty())
    {
        temp = pop();
        if(temp.a==1)
            cout<<"Move disc from "<<temp.from<<" to "<<temp.to<<'\n';
        else{
            push(temp.a-1,temp.aux,temp.from,temp.to);
            push(1,temp.from,temp.aux,temp.to);
            push(temp.a-1,temp.from,temp.to,temp.aux);
        }
    }
}

int main()
{
    int n=3;
    moves(3,'a','b','c');
    return 0;
}

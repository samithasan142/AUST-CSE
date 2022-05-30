#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int a;
    char from,aux,to;

    Stack(int num,char first,char middle,char last){
        a=num;
        from=first;
        aux=middle;
        to=last;
    }
    Stack(){

    };
};
Stack stk[100];

int st_top=0;

void push(int num,char first,char middle,char last)
{
    if(st_top!=100)
    {
        stk[st_top].a=num;
        stk[st_top].from=first;
        stk[st_top].aux=middle;
        stk[st_top].to=last;
        st_top++;
    }
    else cout<<"Stack Overflow";
}

void push(Stack c)
{
    if(st_top!=100)
        stk[st_top++]=c;
    else cout<<"Stack Overflow";
}

Stack pop()
{
    if(st_top!=0)
        return stk[--st_top];
    else cout<<"Stack Underflow";
}

bool isEmpty()
{
    if(st_top==0)
        return 1;
    else return 0;
}

Stack top()
{
    if(st_top!=0)
        return stk[st_top-1];
    else cout<<"Stack Empty";
}

void TOH(int a,char from,char aux,char to)
{
    Stack obj(a,from,aux,to);
    push(obj);

    while(!isEmpty())
    {
        obj = pop();
        if(obj.a==1)
            cout<<"Move disc from "<<obj.from<<" to "<<obj.to<<endl;
        else{
            push(obj.a-1,obj.aux,obj.from,obj.to);
            push(1,obj.from,obj.aux,obj.to);
            push(obj.a-1,obj.from,obj.to,obj.aux);
        }
    }
}

int main()
{
    int a;

    cout<<"Enter number of disks: ";
    cin>>a;
    cout<<endl;
    TOH(a, 'A', 'B', 'C');

    return 0;
}

#include <stdio.h>
#include <iostream>
using namespace std;

int top = -1;
int qu[20];
void push(int x)
{
    top = top+1;
    qu[top]=x;
    //st[top++]=x; // is it right?
    //st[++top]=x;
}
int pop()
{
    int temp = qu[0];
    for(int i=1;i<=top;i++) // think why <= top why not <top
        qu[i-1]=qu[i];
//    for(int i=0;i<top;i++); // think why <top why not <= top
//        qu[i]=qu[i+1]
    top--;
    return temp;
}
bool isEmpty()
{
    if(top==-1)
        return true;
    return false;
    //is it right or should
    //we write else
}
int _size()
{
    //return top++;
    return top+1;
}
int main()
{
    cout<<"Is Empty: "<<isEmpty()<<endl;
    cout<<"Size :"<<_size()<<endl;
    push(5);
    cout<<"After pushing 5.."<<endl;
    push(6);
    cout<<"After pushing 6.."<<endl;
    push(7);
    cout<<"After pushing 7.."<<endl;
    cout<<"Is Empty: "<<isEmpty()<<endl;
    cout<<"Size :"<<_size()<<endl;
    cout<<pop()<<endl;
    cout<<"Is Empty: "<<isEmpty()<<endl;
    cout<<"Size :"<<_size()<<endl;
    cout<<pop()<<endl;
    cout<<"Is Empty: "<<isEmpty()<<endl;
    cout<<"Size :"<<_size()<<endl;
    return 0;
}

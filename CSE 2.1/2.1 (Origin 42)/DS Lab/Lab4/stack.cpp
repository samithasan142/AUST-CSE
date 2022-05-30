#include <stdio.h>
#include <iostream>
using namespace std;

int top = -1;
int st[20];
void push(int x)
{
    top = top+1;
    st[top]=x;
    //st[top++]=x; // is it right?
    //st[++top]=x;
}
int pop()
{
//    int temp = st[top];
//    top--;
//    return temp;
    return st[top--];
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

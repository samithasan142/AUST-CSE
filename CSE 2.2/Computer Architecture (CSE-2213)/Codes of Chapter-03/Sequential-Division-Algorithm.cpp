#include<bits/stdc++.h>
#define fastIo ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

char printBin4(int n)
{
    int arr[10],j=3;
    for(int i=0; i<4; i++)
    {
        int x=n&1;
        if(x==1)
        {
            arr[j--]=1;
        }
        else
        {
            arr[j--]=0;
        }
        n=n>>1;
    }
    for(int i=0; i<4; i++)
    {
        cout<<arr[i];
    }
    return ' ';
}
char printBin8(int n)
{
    int arr[15],j=7;
    for(int i=0; i<8; i++)
    {
        int x=n&1;
        if(x==1)
        {
            arr[j--]=1;
        }
        else
        {
            arr[j--]=0;
        }
        n=n>>1;
    }
    for(int i=0; i<8; i++)
    {
        cout<<arr[i];
    }
    return ' ';
}
void printRow(int iteration,string step,int quotient,int divisor,int remainder)
{
    int gap=10;
    cout<<iteration<<setw(gap+30)<<step<<setw(gap+2)<<printBin4(quotient)<<setw(gap+3)<<printBin8(divisor)<<setw(gap+1)<<printBin8(remainder)<<endl;
}
int main()
{
    fastIo
//    freopen("input.txt","r",stdin);
    int gap=10;
    int dividend,divisor,quotient=0;
    printf("Enter 2 decimal numbers(Dividend Divisor):");
    cin>>dividend>>divisor;
    int remainder=dividend;

    //Iteration 0
    divisor=divisor<<4;
    cout<<"\nIteration"<<setw(gap+15)<<"Step"<<setw(gap+15)<<"Quotient"<<setw(gap+8)<<"Divisor"<<setw(gap+9)<<"Remainder"<<endl;
    printRow(0,"Initial values",quotient,divisor,remainder);

    for(int i=1; i<=5; i++)
    {
        //Step 1
        remainder-=divisor;
        printRow(i,"1: Rem = Rem - Div",quotient,divisor,remainder);

        //Step 2
        if(remainder<0)
        {
            remainder+=divisor;
            quotient<<=1;
            quotient^=0;
            printRow(i,"2b: Rem < 0 => +Div, sll Q, Q0 = 0",quotient,divisor,remainder);
        }
        else
        {
            quotient<<=1;
            quotient|=1;
            printRow(i,"2a: Rem >= 0 => sll Q, Q0 = 1",quotient,divisor,remainder);
        }

        //Step 3
        divisor>>=1;
        printRow(i,"3: Shift Div right",quotient,divisor,remainder);
    }

    return 0;
}


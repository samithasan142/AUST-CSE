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
void printRow(int iteration,string step,int multiplier,int multiplicand,int product)
{
    int gap=10;
    cout<<iteration<<setw(gap+30)<<step<<setw(gap+2)<<printBin4(multiplier)<<setw(gap+3)<<printBin8(multiplicand)<<setw(gap+3)<<printBin8(product)<<endl;
}
int main()
{
    fastIo
//    freopen("input.txt","r",stdin);
    int multiplicand,multiplier,product=0;
    int gap=10;
    printf("Enter 2 decimal numbers(Multiplicand x Multiplier):");
    cin>>multiplicand>>multiplier;
    cout<<"\nIteration"<<setw(gap+15)<<"Step"<<setw(gap+15)<<"Multiplier"<<setw(gap+10)<<"Multiplicand"<<setw(gap+9)<<"Product"<<endl;
    printRow(0,"Initial values",multiplier,multiplicand,product);

    for(int i=1; i<=4; i++)
    {
        //Step 1
        int x=multiplier&1;
        if(x==1)
        {
            product=product+multiplicand;
            printRow(i,"1a: 1 => Prod = Prod + Mcand",multiplier,multiplicand,product);
        }
        else
        {
            printRow(i,"1: 0 => No operation",multiplier,multiplicand,product);
        }
        //Step 2
        multiplicand<<=1;
        printRow(i,"2: Shift left Multiplicand",multiplier,multiplicand,product);

        //Step 3
        multiplier>>=1;
        printRow(i,"3: Shift right Multiplier",multiplier,multiplicand,product);
    }
    return 0;
}


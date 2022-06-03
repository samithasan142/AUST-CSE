#include<bits/stdc++.h>
using namespace std;
int n;
double f(int arr[],double x)
{
    double result=0;
    for(int i=n;i>=0;i--)
        result=result*x+arr[i];
    return result;
}

double df(int arr[],double x)
{
    double result=0;
    for(int i=n;i>0;i--)
        result=result*x+i*arr[i];
    return result;
}
int main()
{
    cout<<"Enter the degree of the equation: ";
    cin>>n;
    double x0,brr[n],xr,e=.001;
    int arr[n][n];
    cout<<"Enter the coefficients of the equation: ";
    for(int i=n;i>=0;i--)
    {
        cin>>arr[n][i];
    }
    cout<<"Enter the initial value: ";
    cin>>x0;
     int ite=0,_n=n,root=1;
    do
    {
        xr=x0-f(arr[n],x0)/df(arr[n],x0);
        while(1)
        {
            x0=xr;
            xr=x0-f(arr[n],x0)/df(arr[n],x0);
            if(abs((xr-x0)/xr)<e)
            {
                break;
            }
        }
        cout<<"itr "<<ite<<"\t"<<"Root "<<root<<": "<<xr<<endl;
        ite++;
        root++;
        brr[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            brr[i]=arr[n][i+1]+brr[i+1]*xr;
        }
        n--;
        for(int i=n;i>=0;i--)
            arr[n][i]=brr[i];
        x0=xr;
    }while(n>1);
    xr=-arr[1][0]/arr[1][1];
    cout<<"itr "<<ite<<"\t"<<"Root "<<root<<": "<<xr<<endl;
    return 0;
}

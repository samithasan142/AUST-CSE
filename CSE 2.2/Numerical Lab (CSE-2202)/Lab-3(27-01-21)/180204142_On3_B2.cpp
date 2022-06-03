#include<bits/stdc++.h>
using namespace std;

int n=3;
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
    double x0,brr[n],xr,e=0.001;
    int arr[n][n];
    cout<<"Enter values of coefficients : \n";
    for(int i=n;i>=0;i--)
    {
        printf("Coefficient x[%d]=",i);
        cin>>arr[n][i];
        printf("\n");
    }
    cout<<"Enter the initial value: ";
    cin>>x0;
    printf("The %d order polynomial is: (%d)x^3+(%d)x^2+(%d)x^1+(%d)x^0\n", n, arr[n][3], arr[n][2], arr[n][1], arr[n][0]);
    int ite=1,n2=n;
    double root=1;
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

        printf("At order %d the Root is %.6lf\n", n, xr);
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
    printf("At order %d the Root is %.6lf\n", n, xr);
    printf("\nThere are %d Roots for the given polynomial\n", n2);
    return 0;
}


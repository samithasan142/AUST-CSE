#include<bits/stdc++.h>
using namespace std;
double horner(double poly[], int n, double x)
{
    double result = poly[0];

    for (int i=1; i<n; i++)
    {
        result = result*x + poly[i];
    }
    return result;
}

int main()
{

    int n;
    cout<<"Enter the degree of the equation: ";
    cin>>n;
    n++;
    double poly[n+1];
    cout<<"Enter the coefficients of the equation: ";
    for(int i=0;i<n;i++)
        cin>>poly[i];
    cout<<"Enter the initial values: ";


    double f0,f1,f2,xlow,xup,delx,x0,x1,x2,E=0.00001,e,root;

    ///1///
    cin>>xlow>>xup;

    ///2///
    delx=0.1;
    ///3///

    for(int i=1;x2<=xup;)
    {
        x1=xlow,x2=xlow+delx;
        ///4///
        f1=horner(poly,n,x1);
        f2=horner(poly,n,x2);
        ///5///
        double ans = abs(f1*f2);
        if(ans<0.000001)
        {

            for(;;i++)
            {
                ///6///
                x0=(x1+x2)/2;
                f0=(poly,n,x0);
                ///7///
                if((f1*f0)<0)
                    x2=x0;
                else
                {
                    x1=x0;
                    f1=f0;
                }
                ///8///
                e = abs((x2-x1)/x2);
                if(e<E)
                {
                    root = (x1+x2)/2;
                    cout<<i<<") root = "<<root<<'\n';
                    if(x2<xup) xlow=x2;
                    break;
                }
            }
        }
        else
        {
            ///9///
            if(x2<xup) xlow=x2;
        }
        cout<<"x1 = "<<x1<<"  x2 = "<<x2<<"  up = "<<xup<<"  f1*f2 = "<<(f1*f2)<<'\n';
    }

    return 0;
}

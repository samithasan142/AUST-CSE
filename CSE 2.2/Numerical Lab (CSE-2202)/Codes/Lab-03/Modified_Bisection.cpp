#include<bits/stdc++.h>
using namespace std;

double arr[100];
double error=0.00001;
int n;

double func(double x)
{
    double res=arr[n];
    for(int i=n-1; i>=0; i--)
        res=res*x+arr[i];
    return res;
}

int main()
{
    int i,j,k;
    cout << "Enter the degree of the equation: ";
    cin >> n;
    cout << "Enter the coefficients of the equation(from maximum power): ";
    for(i=n; i>=0; i--)
        cin>>arr[i];

    double a,b,dx=0.1;
    cout<<"Enter the initial values (lower and upper limit): ";
    cin >> a >> b ;

    while(true)
    {
        double x1,x2,f1,f2;
        x1=a;
        x2=x1+dx;
        f1=func(x1);
        f2=func(x2);

        if(f1*f2<0)
        {
            while(true)
            {
                f1=func(x1);
                f2=func(x2);
                double x0=(x1+x2)/2;
                double f0=func(x0);

                if(f1*f0<0)
                    x2=x0;
                else
                    x1=x0;

                double e = fabs((x2-x1)/x2);
                if(e<=error)
                {
                    cout<<endl;
                    cout<<"Between "<<x1<<" and "<<x2<<" there is a root "<<x0<<endl;
                    break;
                }
            }
        }
        if(x2<b)
            a=x2;
        else
            break;
    }
}

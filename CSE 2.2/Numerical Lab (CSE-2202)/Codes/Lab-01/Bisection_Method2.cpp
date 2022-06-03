#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double func(double x)
{
    return x*x*x - x - 1;
}

double es=0.01;
double root, error, f0, f1, f2;

void bisection(double a, double b)
{
    f1=func(a);
    f2=func(b);
    if(f1*f2> 0)
    {
        printf("No Root Lying between %lf and %lf", a, b);
        return;
    }
    //root=a;
    error = fabs((b-a)/b);
    cout<<error<<"\n";
    while(error > es)
    {
        error = fabs((b-a)/b);
        f1=func(a);
        f2=func(b);
        root=(a+b)/2;
        f0=func(root);
        /*if(f0==0.0)
        {
            printf("Root=%lf\n",root);
            break;
        }*/
        if(f1*f0<=0)
        {
            printf("a=%lf   b=%lf   Root=%lf\n", a, b, root);
            b=root;
        }
        else
        {
            printf("a=%lf   b=%lf   Root=%lf\n", a, b, root);
            a=root;
        }

    }
}

int main()
{
    double a,b;
    printf("Enter the lower range (a)):");
    scanf("%lf", &a);
    printf("Enter the upper range (b)):");
    scanf("%lf", &b);

    printf("The function used is x^3-x-1\n");
    printf("a=%lf\n",a);
    printf("b=%lf\n",b);
    bisection(a,b);
    printf("\n");
    printf("Accurate root calculated is = %lf\n",root);

    return 0;
}

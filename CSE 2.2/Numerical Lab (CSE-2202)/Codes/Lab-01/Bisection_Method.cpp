#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x*x*x - 2*x*x + 3;
    //return x*x*x - x - 1;
}

double e=0.01;
double c;

void bisection(double a, double b)
{
    if(func(a)*func(b)>= 0)
    {
        printf("No Root Lying between %lf and %lf", a, b);
        return;
    }
    c=a;
    while((b-a)>= e)
    {
        c=(a+b)/2;
        if(func(c)==0.0){
            printf("Root=%lf\n",c);
            break;
        }
        else if(func(c)*func(a)<0){
            printf("a=%lf   b=%lf   Root=%lf\n", a, b, c);
            b=c;
        }
        else{
            printf("a=%lf   b=%lf   Root=%lf\n", a, b, c);
            a=c;
        }
    }
}

int main()
{
    double a,b;
    printf("Enter the lower range (a)):");
    scanf("%lf", &a);
    printf("Enter the lower range (b)):");
    scanf("%lf", &b);

    printf("The function used is x^3-2x^2+3\n");
    printf("a=%lf\n",a);
    printf("b=%lf\n",b);
    bisection(a,b);
    printf("\n");
    printf("Accurate root calculated is = %lf\n",c);

    return 0;
}

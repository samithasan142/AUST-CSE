#include<bits/stdc++.h>
using namespace std;
#define ERROR 0.01

double  coeff[100];
int n;


double horners(double x)
{
    double b = 0;
    int i;
    for(i=0; i<=n; i++)
    {
        b = b*x + coeff[i]; ///result = result*x + poly[x];
    }
    return b;
}
/*double func(double x)
{
	return 5*x*x*x - 5*x*x +6*x- 2;
}
*/

int main()
{
    int i;
    double x;
    printf("Enter the highest degree of the equation: ");
    scanf("%d",&n);

    printf("\nEnter values of coefficients: ");
    for(i=0;i<=n;i++)
    {
        printf("\nCoefficient x[%d] = ", n-i); // 2x^3 – 6x^2 + 2x – 1
        scanf("%lf",&coeff[i]);
    }

    cout<<"input the initial value(x): ";
    cin>>x;

    double res = horners(x);

    cout<<"result of horner's is: "<<res<<endl;

    //cout<<"result of geeks func is: "<<func(x)<<endl;

    return 0;
}

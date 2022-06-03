#include<bits/stdc++.h>
using namespace std;

double  coeff[100];
int n;


double ho(double x)
{
    double b = 0;
    int i;
    for(i=0; i<=n; i++)
    {
        b = b*x + coeff[i]; ///result = result*x + poly[x];
    }
    return b;
}

void secant(double x1, double x2, double E)
{
    float n = 0, xm, x0, c;
    if (ho(x1) * ho(x2) < 0) {
        do {
            // calculate the intermediate value
            x0 = (x1 * ho(x2) - x2 * ho(x1)) / (ho(x2) - ho(x1));

            // check if x0 is root of equation or not
            c = ho(x1) * ho(x0);

            // update the value of interval
            x1 = x2;
            x2 = x0;

            // update number of iteration
            n++;

            // if x0 is the root of equation then break the loop
            if (c == 0)
                break;
            xm = (x1 * ho(x2) - x2 * ho(x1)) / (ho(x2) - ho(x1));
        } while (fabs(xm - x0) >= E); // repeat the loop
                                // until the convergence

        cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << n << endl;
    } else
        cout << "Can not find a root in the given inteval";
}

int main()
{
    int i;
    double x, E = 0.0001, x1=1, x2=3;
    printf("Enter the total no. of power: ");
    scanf("%d",&n);

    printf("\nEnter values of coefficients: ");
    for(i=0;i<=n;i++)
    {
        printf("\n x^[%d] :: ", n-i);
        scanf("%lf",&coeff[i]);
    }

    printf("The polynomial is ::: 1x^3 + 0x^2 - 1x^1 - 3x^0\n");

    secant(x1, x2, E);
    //cout<<"input the initial value(x): ";
    //cin>>x;

    //double res = horners(x);

    //cout<<"result of horner's is: "<<res<<endl;

    return 0;
}


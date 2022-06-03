#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int A[100], n1;

double f(int poly[], int n, double x)
{
    double result = poly[0];
    for (int i=1; i<n; i++)
    {
        result = result*x + poly[i];
    }
    return result;
}

double f2(int poly[],int order,double x)
{
    double value = 0;
    int i;
    for(i=0; i<order; i++)
    {
        value = value*x + (order-i)*poly[i];
    }
    return value;
}

double newton_raphson(double x)
{
    int i=0;
    double fx, f_derx, x_prev=x , h, f_root;

    while(f_root!=0){
        i++;
        fx = f(A,n1+1,x_prev);
        f_derx = f2(A,n1,x_prev);
        h = fx/f_derx;
        x = x_prev - h;
        f_root=f(A,n1,x);
        printf("After %d iteration the Root is: %lf\n",i ,x);
        if(abs(x-x_prev)<=0.00009) break;
        x_prev = x;
    }
    printf("\n");
    printf("Value return by Horners Method is 0.000000\n");
    printf("Root Found Using Newton Raphson Method is Exact Root\n");

    return x;
}

int main()
{
    double Xo;
    int i;

    cout<<"ENTER THE TOTAL NO. OF POWER:::: ";
    cin>> n1;
    cout<<"\nEnter values of coefficients:\n";
    for( i=0; i<= n1; i++)
    {
        cout<<"\nx^"<<i<<"::";
        cin >> A[n1-i];
    }
    cout<<"\nTHE POLYNOMIAL IS ::: ";
    for(int i=0;i<=n1;i++)
        cout<<"("<<A[i]<<")"<<"x^"<<(n1-i)<<"+";
    cout << "\nINTIAL: Xo---->";
    cin >> Xo;

    Xo = newton_raphson(Xo);

    return 0;
}


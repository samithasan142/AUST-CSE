#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int A[100],n1;


double f(int poly[], int n, double x)
{
    double result = poly[0];
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

double f2(int poly[],int order,double x)
{
    double value =  0;
    int i;
    for(i=0; i<order; i++)
    {
        value = value*x + (order-i)*poly[i];
    }
    return value;
}




double newton_raphson(double x)
{
    double fx=2,f_derx=1,x_prev=x,i=0,h;
    cout<<"\n**************************************"<<'\n';
    cout<<"ITERATION X1 FX1 F'X1"<<'\n';
    cout<<"**************************************"<<'\n';

    while(true){
        i++;
        fx = f(A,n1+1,x_prev);
        f_derx = f2(A,n1,x_prev);
        h = fx/f_derx;
        x = x_prev - h;
        cout<<i<<"\t "<<x<<"   "<<fx<<"   "<<f_derx<<'\n';
        if(abs(x-x_prev)<=0.00009) break;
        x_prev = x;
    }
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
    cout << "\n Approximate root: "<< Xo ;
    return 0;
}

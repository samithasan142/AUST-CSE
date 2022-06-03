#include<iostream>
#include<cmath>
using namespace std;

double func(double );
double first_derivative(double );
void newton_raphson(double ,double );

int main()
{
    double x2,e;

    cout<<"Enter the initial guess: ";
    cin>>x2;

    cout<<"Enter desired accuracy: ";
    cin>>e;

  newton_raphson(x2,e);

    return 0;
}

double func(double x)
{
    int arr[4] = {1,0,-1,-3};
        double ans=arr[0];
        for (int i=1; i<4; i++)
        {
            ans=(ans*x+arr[i]);
        }
        return ans;
}

double first_derivative(double x)
{
    int arr[3] = {3,0,-1};
        double ans=arr[0];

        for (int i=1; i<3; i++)
        {
            ans=(ans*x+arr[i]);
        }
        return ans;
}

void newton_raphson(double x2, double e)
{
    double x1;

    do
    {
      x1=x2;

        x2 = x1 - func(x1)/first_derivative(x1);

    }while(fabs(x2-x1) >= e);

  cout<<"\nThe root of an equation is "<<x2;
}

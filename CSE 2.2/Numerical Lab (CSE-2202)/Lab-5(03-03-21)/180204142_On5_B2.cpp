#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
double x[100], y[100][100],approx_res[100],sum_x=0,sum_y=0,true_res[100];

double productTerm(int i,double value)
{
    double pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (value - x[j]);
    }
    return pro;
}

void dividedDiffTable()
{
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
            //y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[i+j] - x[j]);
        }
    }
}

double applyFormula(double value)
{
    double sum = y[0][0];
    for (int i = 1; i < n; i++)
    {
      sum = sum + (productTerm(i, value) * y[0][i]);
    }
    return sum;
}


int main()
{
    cout<<"Enter number of data points: ";
    cin>>n;
    cout<<"Enter values of Year and Average Temperature in Degree Celsius "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i][0];
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i][0];
    }
    dividedDiffTable();
    cout<<"Year\tApproximate Average Temperature in Degree Celsius"<<endl;
    double approx_x,true_x;
    double value=2020,h=1;
    while(value<=2040)
    {
        approx_x=applyFormula(value);
        approx_res[cnt]=approx_x;

        printf("%.2f\t\t%f\n",value,approx_x);
        cnt++;
        value=value+h;
    }

    cout<<"\nFunction\t\t\t\t\t  Value\n";

    double sam=0;

    for(int i=0;i<n;i++)
    {
        sam=sam+pow((y[i][0]-approx_res[i]),2);
    }
    printf("Mean Squared Error (MSE)\t\t\t %f\n",sam/n);
    printf("A0 \t\t\t\t\t\t %f\n",y[0][0]);
    printf("A1 \t\t\t\t\t\t %f\n",y[0][1]);
    printf("A2 \t\t\t\t\t\t %f\n",y[0][2]);
    printf("A3 \t\t\t\t\t\t %f\n",y[0][3]);
    return 0;
}

/*
21

1993 25.00317
1994 25.26167
1995 25.41583
1996 25.44025
1997 24.85925
1998 25.52417
1999 25.71483
2000 25.15017
2001 25.337
2002 25.38033
2003 25.28083
2004 25.38633
2005 25.532
2006 25.76567
2007 25.34375
2008 25.3895
2009 25.90492
2010 25.94033
2011 25.20508
2012 25.53358
2013 25.9675

*/

/*
2013 25.9675
2012 25.53358
2011 25.20508
2010 25.94033
2009 25.90492
*/


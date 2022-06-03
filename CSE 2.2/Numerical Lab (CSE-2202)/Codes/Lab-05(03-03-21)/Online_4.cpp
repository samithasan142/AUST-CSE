#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
double x[100], y[100][100],approx_res[100],sum_x=0,sum_y=0,true_res[100];

double proterm(int i,double value)
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
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

double applyFormula(double value)
{
    double sum = y[0][0];
    for (int i = 1; i < 4; i++)
    {
      sum = sum + (proterm(i, value) * y[0][i]);
    }
    return sum;
}

void printDiffTable()
{
    cout<<"The divide difference table is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setprecision(4) <<y[i][j] << "\t ";
        }
        cout << "\n";
    }
}

int main()
{
    cout<<"Enter number of points: ";
    cin>>n;
    cout<<"Enter values of x and f(x) "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i][0];
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i][0];
    }
    dividedDiffTable();
    cout<<"X\tApproximated cube root of x\tTrue Value of cubic root x"<<endl;
    double value=1.24,h=0.01,approx_x,true_x;
    while(value<=1.70)
    {
        value=value+h;
        approx_x=applyFormula(value);
        approx_res[cnt]=approx_x;
        true_x=cbrt(value);
        true_res[cnt]=true_x;
        printf("%.2f\t\t%f\t\t\t%f\n",value,approx_x,true_x);
        cnt++;
    }
    //printDiffTable();
    cout<<"\nFunction\t\t\t\t\t  Value\n";
    printf("Mean of x\t\t\t\t\t %f\n",sum_x/n);
    printf("Mean of y\t\t\t\t\t %f\n",sum_y/n);
    double sam=0;
    for(int i=0;i<20;i++)
    {
        sam=sam+pow((true_res[i]-approx_res[i]),2);
    }
    printf("Mean Squared Error (MSE) for data size 20\t %f\n",sam/20);
    sam=0;
    for(int i=0;i<30;i++)
    {
        sam=sam+pow((true_res[i]-approx_res[i]),2);
    }
    printf("Mean Squared Error (MSE) for data size 30\t %f\n",sam/30);
    printf("A1 \t\t\t\t\t\t %f\n",y[0][0]);
    printf("A2 \t\t\t\t\t\t %f\n",y[0][1]);
    printf("A3 \t\t\t\t\t\t%f\n",y[0][2]);
    printf("A4 \t\t\t\t\t\t%f\n",y[0][3]);
    return 0;
}

/*

1.0 1.0
1.1 1.032
1.2 1.063
1.3 1.091
1.4 1.119
1.5 1.145
1.6 1.170
1.7 1.193
1.8 1.216
1.9 1.239
2.0 1.260

*/



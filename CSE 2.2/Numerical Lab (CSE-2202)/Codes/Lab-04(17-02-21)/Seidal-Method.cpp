#include<bits/stdc++.h>
using namespace std;

int i,j,k,n;

void showMatrix(double a[100][100])
{
    cout<<"Given equation:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j<n)
            {
                cout<<a[i][j]<<"x"<<j+1;
                if(j<n-1&&a[i][j+1]>=0)
                    cout<<"+";
            }
            else
            {
                cout<<"= "<<a[i][j];
            }

        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter order of matrix= ";
    cin>>n;
    double a[100][100],x[n],sum,x1=1;
    double p;
    cout<<"Enter elements:"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
        {
            cout<<i+1<<"."<<j+1<<"= ";
            cin>>a[i][j];
        }
    showMatrix(a);
    for(i=0;i<n;i++)
        x[i]=0;
    while(1)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    sum+=a[i][j]*x[j];
            }
            x[i]=(a[i][n]-sum)/a[i][i];
        }
        if(abs(x1-x[0])/x1<0.0001)
        {
            break;
        }
        x1=x[0];
    }
    cout<<"Solution:"<<endl;
    for(i=0;i<n;i++)
        cout<<"x"<<i+1<<"= "<<x[i]<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define max 24

double X[]={0,5.88 ,5.87 ,7.44 ,7.24 ,6.68 ,6.89 ,6.57 ,6.24 ,6.04 ,5.96 ,7.39,7.5 , 7.26,6.93 ,6.64,6.72 ,6.91 ,6.68 ,6.15,6.29 ,7.29  ,7.19,7.39 };
double Y[]={0,34.131,34.078,34.223,34.219,34.229,34.263,34.208,34.145,34.123,34.089,34.264,34.261, 34.271,34.214,34.194,34.237,34.223,34.278, 34.138,34.094,34.241, 34.224,34.268};
double C[max][max],A[max],B[max],Xt[max];
int N=23,MP=3,M;
double arr[24][24];

double f(double arr[],double x,int n)
{
    double result=0;
    for(int i=n;i>=1;i--)
        result=result*x+arr[i];
    return result;
}

void Normal()
{
    int i,j,k;
    double L1,L2;

    for(j=1; j<=M+1; j++)
    {
        for(k=1; k<=M+1; k++)
        {
            C[j][k]=0.0;
            L1 = k+j-2;
            for(i=1; i<=M+1; i++)
            {
                C[j][k] = C[j][k] + pow(X[i],L1);///an+a2*sumx+a3*sumx^2+a4*sumx^3
            }
        }
    }
    C[1][1]=N;
    for(j=1; j<=M+1; j++)
    {
        B[j] = 0.0;
        L2 = j-1;
        for(i=1; i<=M+1; i++)
        {
            B[j] = B[j] + (Y[i] * pow(X[i],L2));
        }
    }
    /*for(i = 1; i<M+1; i++)
    {
        for(j=1; j<M+1; j++)
        {
            cout<<C[i][j]<<"   ";
        }
        cout<<endl;
    }*/
}

void Gauss()
{
    int k,i,j;
    double factor,sum;


    for(k=1; k<M; k++)
    {
        for(i=k+1; i<M+1; i++)
        {
            factor=C[i][k]/C[k][k];
            for(j=k+1; j<=M+1; j++)
            {
                C[i][j]=C[i][j]-C[k][j]*factor;
            }
            B[i] = B[i] - factor*B[k];
        }
    }

    Xt[M] = B[M]/C[M][M];

    for(k=M; k>=1; k--)
    {
        sum=0;
        for(j=k+1; j<M+1; j++)
        {
            sum = sum + (C[k][j]*Xt[j]);
        }

        Xt[k]=(B[k]-sum)/C[k][k];
    }

}



int main()
{
    int i,j,k;
    double sumx=0;
    for(int i=1; i<=N; i++)
    {
        sumx+=X[i];
    }
    double sumy=0;
    for(int i=1; i<=N; i++)
    {
        sumy+=Y[i];
    }

    double sumxx=0;
    for(int i=1; i<=N; i++)
    {
        sumxx+=X[i]*X[i];
    }
    double sumyy=0;
    for(int i=1; i<=N; i++)
    {
        sumyy+=Y[i]*Y[i];
    }

    double sumxy=0;
    for(int i=1; i<=N; i++)
    {
        sumxy+=X[i]*Y[i];
    }

    M = MP+1;

    Normal();
    Gauss();

    for(i=1; i<=M; i++)
    {
        cout<<Xt[i]<<" ";
    }

    cout<<endl;

    cout<<"T_degCWater\tSalnty"<<endl;
    double x=5;
    do
    {
        cout<<x<<"\t\t"<<f(Xt,x,M)<<endl;
        x+=.1;
    }while(x<6);

    double r=(N*sumxy-sumx*sumy)/(sqrt((N*sumxx-sumx*sumx)*(N*sumyy-sumy*sumy)));
    if(r>0)
        cout<<"\nStrong Positive Relation"<<endl;
    else if(r<0)
        cout<<"\nStrong Negative Relation"<<endl;
    else if(r==0)
        cout<<"\nNo Relation at all"<<endl;

    cout<<endl;
}


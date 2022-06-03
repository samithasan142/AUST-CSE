#include <iostream>
using namespace std;

bool selceted[10]= {0};

int kS(int W, int w[], int v[], int n)
{
    int i, wt;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= W; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (w[i - 1] <= wt)
            {
                if(v[i - 1] + K[i - 1][wt - w[i - 1]]> K[i - 1][wt])  K[i][wt] = v[i - 1] + K[i - 1][wt - w[i - 1]];
                else K[i][wt] =  K[i - 1][wt];
            }

            else
                K[i][wt] = K[i - 1][wt];
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
            cout<<K[i][j]<<" ";
        cout<<"\n";
    }

    return K[n][W];
}
int main()
{
    int n=4,W=6;  /// n=number of elements, W=Max capacity
    int v[n]= {12,14,25,10}, w[n]= {1,3,4,2};   /// W[n]=weight, V[n]=Benefit

    //int n=3,W=6;
    //int v[n]= {10,15,40}, w[n]= {1,2,3};

    //int n=3,W=50;
    //int v[n]= {60,100,120}, w[n]= {10,20,30};

    cout << kS(W, w, v, n);
    return 0;
}

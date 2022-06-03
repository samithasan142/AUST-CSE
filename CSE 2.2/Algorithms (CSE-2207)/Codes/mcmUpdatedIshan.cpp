#include <bits/stdc++.h>
using namespace std;
const int n=4;
int m[4][4];
int s[4][4];

void printPath(int s[n][n],int i ,int j){

    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        printPath(s,i,s[i][j]);
        printPath(s,s[i][j]+1,j);
        cout<<")";

    }
}
int MatrixChainOrder(int p[], int n)
{


	int i, j, k, L, q;

	for (i = 1; i < n; i++){
		m[i][i] = 0;
		s[i][i]=0;
	}


	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			cout<<"m["<<i<<","<<j<<"]"<<endl;
			for (k = i; k <= j - 1; k++)
			{

				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				cout<<"m ["<<i<<","<<k<<"] ("<<m[i][k]<<") + " ;
				cout<<"m ["<<k+1<<","<<j<<"] ("<<m[k+1][j]<<") + " ;
				cout<<"P"<<i-1<<"P"<<k<<"P"<<j<<" ("<<p[i - 1] * p[k] * p[j]<<") = "<<q<<"(k= "<<k<<")"<<endl;
                //cout<<q<<endl;

				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j]=k;
				}
			}
			cout<<endl;
		}
	}

	cout<<"M matrix or cost matrix" <<endl;
    for(int i=1;i<n;i++){

        for(int j=1;j<n;j++){
            if(i>j){
                cout<<"dn ";
            }
            else{
                cout<<m[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"S matrix " <<endl;
     for(int i=1;i<n;i++){

        for(int j=1;j<n;j++){
            if(i>=j){
                cout<<"dn ";
            }
            else{
                cout<<s[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    cout<<endl;
    printPath(s,1,4);
    cout<<endl<<endl;

	return m[1][n - 1];

}


int main()
{
    //cin>>n;

	int arr[] = { 5,3,3,2,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	//n=size;
    int cost=MatrixChainOrder(arr, size);
	cout << "Cost is :  "<< cost<<endl;
	int d;
	cin>>d;
}



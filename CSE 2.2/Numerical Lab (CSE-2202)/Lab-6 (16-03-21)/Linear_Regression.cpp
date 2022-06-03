#include<bits/stdc++.h>
#define S 50
using namespace std;

int main()
{
    int n, i;
    float x[S], y[S], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;

    printf("Enter no of data points: ");
    scanf("%d",&n);

    printf("\nEnter data:\n");

    for(i=1; i<=n; i++)
    {
        printf("x[%d]= ",i);
        scanf("%f",&x[i]);
        printf("y[%d]= ",i);
        scanf("%f",&y[i]);

    }


    for(i=1; i<=n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i]*x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i]*y[i];
    }

    b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    a = (sumY - b*sumX)/n;

    printf("\nCalculated value of a is %f and b is %f: ",a,b);
    printf("\nEquation of best fit is: y = %f+%fx",a,b);


    return(0);
}

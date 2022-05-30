#include <stdio.h>
int main()
{
    float n, i, sum = 0, avg;

    printf("Enter a positive number: ");
    scanf("%f",&n);

    for(i=1; i<=n; i++)
    {
        sum= sum+i ;
    }
        avg=sum/n ;

    printf("\nSum of the numbers = %.2f",sum);
    printf("\nAvg of the numbers = %.2f",avg);

    return 0;
}

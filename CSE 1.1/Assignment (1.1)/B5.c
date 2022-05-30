#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    if(n%7==0)

        printf("\nThe number is divisible by 7");

    else printf("\nThe number is not divisible by 7");
    return 0;
}

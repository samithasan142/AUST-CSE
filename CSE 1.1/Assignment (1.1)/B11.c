#include<stdio.h>
int main()
{
    int s,c,profit,loss;
    printf("Input the selling price:");
    scanf("%d",&s);
    printf("Input the cost price:");
    scanf("%d",&c);
    if(s>c)
    {
        printf("The seller has made profit");

        profit=s-c;
        printf("\nprofit is %d",profit);
    }
          else
          {
            printf("The seller has incurred loss");

            loss=c-s;
            printf("\nloss is %d",loss);
          }
    return 0;
}

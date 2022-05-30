#include<stdio.h>
int main()
{
    int num,r,sum=0,temp;
    printf("Enter the number:");
    scanf("%d",&num);

         temp=num;

         while(temp>0)
         {
             r=temp%10;
             temp=temp/10;
             sum=sum+(r*r*r);
         }
         if(sum==num)
         {
             printf("The number is Armstrong number");
         }
         else
         {
             printf("The number is not an Armstrong number");
         }

         return 0;
}

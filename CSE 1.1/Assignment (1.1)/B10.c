#include<stdio.h>
int main()
{
    int salary;
    float tax;
    printf("Enter your monthly salary:");
    scanf("%d",&salary);
    if(salary>=9000)
    {
        tax=salary*0.4;
        printf("The tax is %.2f",&tax);
    }
    else if(salary>=7500&&salary<9000)
    {
         tax=salary*0.3;
         printf("The tax is %.2f",&tax);
    }
    else if(salary<7500)
    {
       tax=salary*0.2;
       printf("The tax is %.2f",&tax);
    }
    else printf("Invalid");
    return 0;
}

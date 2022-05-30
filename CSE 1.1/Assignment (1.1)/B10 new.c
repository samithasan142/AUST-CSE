#include<stdio.h>
int main()
{
    int salary;
    float tax;
    printf("Enter your monthly salary:");
    scanf("%d",&salary);
    if(salary>=9000)
        tax=salary*0.4;

    else if(salary>=7500&&salary<9000)
        tax=salary*0.3;

    else
        tax=salary*0.2;

    printf("The tax is %f",tax);

    return 0;
}

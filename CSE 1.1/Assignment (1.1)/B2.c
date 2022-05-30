#include<stdio.h>
int main()
{
    int age;
    printf("Enter the age of a person:");
    scanf("%d",&age);
    if(age>19)
        printf("Eligible for professional driving.");
    else if(age>=18)
        printf("Eligible for driving.");
    else printf("Not eligible for driving.");
    return 0;
}

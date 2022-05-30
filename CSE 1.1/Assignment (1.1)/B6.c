#include<stdio.h>
int main()
{
    char name[10];
    int age;
    printf("Enter a name:");
    scanf("%s",&name);
    printf("\nEnter age:");
    scanf("%d",&age);
    if(age>0&&age<=12)
        printf("\nCHILD");
    else if(age>12&&age<=19)
       printf("\nTEENAGER");
    else printf("Invalid");
    return 0;
}


#include<stdio.h>
int main()
{
    int a[5];
    int i,per;
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    per=((a[0]+a[1]+a[2]+a[3]+a[4])/5);
    if(per>=60&&per<=100)
        printf("First division");

    else if(per>=50&&per<=59)
        printf("Second division");

    else if(per>=40&&per<=49)
        printf("Third division");

    else if(per<40)
        printf("Fail");

    else printf("Invalid");
    return 0;


}


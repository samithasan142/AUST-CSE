#include<stdio.h>
int main()
{
    int c,x,y;
    printf("Enter two numbers:");
    scanf("%d%d",&x,&y);
    printf("Enter choice:");
    scanf("%d",&c);
    if(c==1) printf("%d",x+y);
    else if(c==2) printf("%d",x-y);
    else if(c==3) printf("%d",x*y);
    else if(c==4) printf("%d",x/y);
    else if(c==5) printf("%d",x%y);
    else printf("Invalid");
    return 0;
}

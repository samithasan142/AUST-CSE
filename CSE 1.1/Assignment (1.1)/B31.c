#include<stdio.h>
int main()
{
    int i,x,y;
    printf("Enter the two numbers:");
    scanf("%d%d",&x,&y);
    if(x<y)
    {
        for(i=x+1;i<y;i++)
            printf("%d\n",i);
    }
    else if(x>y)
    {
        for(i=y+1;i<x;i++)
            printf("%d\n",i);
    }
    return 0;
}

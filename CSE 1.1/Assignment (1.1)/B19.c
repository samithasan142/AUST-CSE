#include<stdio.h>
int main()
{
    int x,y,z;
    printf("Enter the three numbers:\n");
    scanf("%d%d%d",&x,&y,&z);
    if(x>y&&x>z)
        printf("x is largest");
    else if(y>x&&y>z)
        printf("y is largest");
    else printf("z is largest");
    return 0;
}

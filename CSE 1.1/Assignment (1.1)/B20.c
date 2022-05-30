#include<stdio.h>
int main()
{
    int n1, n2, n3, highest, medium, lowest;
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n1>n2)
    {
        medium=n1;
        lowest=n2;
    }
    else
    {
        medium=n2;
        lowest=n1;
    }
    if(medium>n3)
    {
        higest=medium;
    }
    if(lowest>n3)
    {
        medium=lowest;
        lowest=n3;
    }
    else
        {
            medium=n3;
        }
        else
        {
            higest=n3;
        }
        printf("%d\n%d\n%d",&highest, &medium, &lowest);
        return 0;



}

#include<stdio.h>
int main()
{
    int c,u;
    printf("Enter the rate:");
    scanf("%d",&u);

    if(u>=0 && u<=100)
        c=u*40+50;
    else if(u>=101 && u<=300)
        c=u*50+50;
    else if(u>300)
        c=u*60+50;
    printf("The charge is (in paisa) %d",c);
    return 0;
}

#include<stdio.h>
int main()
{
    char ch;
    printf("Enter any character:");
    scanf("%c",&ch);
    if(ch>=65 && ch<=90)
    {
        printf("Capital Letter");
    }
    else if(ch>=97 && ch<=122)
    {
        printf("Small Letter");
    }
    else if(ch>=48 && ch<=57)
    {
        printf("Digit");
    }
    else if((ch>=33 && ch<=47)||(ch>=58 && ch<=64)||(ch>=91 && ch<=96)||(ch>=123 && ch<=127))
    {
        printf("Special Symbol");
    }
    else printf("Invalid");
    return 0;
}

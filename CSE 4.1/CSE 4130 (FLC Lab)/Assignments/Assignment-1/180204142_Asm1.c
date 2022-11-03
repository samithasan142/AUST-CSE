/* CSE 4130 (Fall 2021)                  Assignment - 1                   ID: 180204142  */
#include<stdio.h>

int main()
{
    FILE *file1, *file2;
    char c;
    int count=0, multicomment=0, space=0;

    file1= fopen("input1.c","r");
    file2 = fopen("output.txt","w");

    if(!file1)
        printf("\nFile not found!!");

    while((c=fgetc(file1))!=EOF)
    {
        if(c=='/')
            count++;

        else if(c=='*' && multicomment==1)
            multicomment=0;

        else if(c=='*' && count==1)
            multicomment=1;

        else if(multicomment==1)
        {

        }
        else if(c!='\n' && count==2)
        {

        }
        else if(c=='\t')
        {

        }
        else if(c==' '&& space ==0)
        {
            fputc(c,file2);
            space++;
        }
        else if(c=='/'&& multicomment==0 && count==1)
        {
            count--;
        }
        else if(c=='\n' && multicomment!=0)
        {
            count=0;
        }
        else if(c=='\n' && count!=1)
        {
            count=0;
            space=0;
        }
        else if(c=='\n' )
        {
            space=0;
        }
        else if(c!=' ')
        {
            fputc(c,file2);
            space=0;
        }

    }
    fclose(file1);
    fclose(file2);
    file1= fopen("input1.c","r");
    file2 = fopen("output.txt","r");

    printf("Input File:\n");
    while((c=fgetc(file1))!=EOF)
        printf("%c",c);
    fclose(file1);
    printf("\n");

    printf("Output File:\n");
    while((c=fgetc(file2))!=EOF)
        printf("%c",c);
    fclose(file2);
    printf("\n");

    return 0;
}

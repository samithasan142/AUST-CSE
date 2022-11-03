/* CSE 4130 (Fall 2021)                  Assignment - 3                   ID: 18.02.04.136                */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int index = 0;

struct symbolTable
{
    char name[15][15];
    char idType[15][15];
    char dataType[15][15];
    char scope[15][15];
    char value[13][13];
} table;

void insert(char name2[15],char dataType2[15],char idType2[15],char scope2[15], char value2[13])
{
    strcpy(table.name[index],name2);
    strcpy(table.dataType[index],dataType2);
    strcpy(table.idType[index],idType2);
    strcpy(table.scope[index],scope2);
    strcpy(table.value[index],value2);
    index++;
}

void set_attribute(char name2[15],char scope2[15], char value2[13])
{
    for(int i=0;i<index;i++){
        if( strcmp(table.name[i],name2)==0 && strcmp(table.scope[i],scope2)==0 ){
            strcpy(table.value[i],value2);
            break;
        }
    }
}

void display()
{
    printf("SL NAME IDTYPE DATATYPE SCOPE VALUE\n");
    for(int i=0; i<index; i++)
    {
        printf("%d   %s  %s   %s  %s  %s\n",(i+1),table.name[i],table.idType[i],table.dataType[i],table.scope[i],table.value[i]);
    }
}


int main()
{
    int j;
    char c1[2000];
    FILE *p1;
    char c;
    p1 = fopen("input.c","r");

    if(!p1) printf("File couldn't be opened ! ");
    else
    {
        int i = 0,j=0;
        printf("The input file : \n\n");
        while((c=fgetc(p1)) != EOF)
        {
            c1[i] = c;
            printf("%c",c1[i++]);
        }
        c1[i] = '\0';
        fclose(p1);
        printf("----------------------------\n\n");


        int n=0;
        char scp[15] = "global";
        char tempScp[15];
        for(j=0; j<i; j++)
        {
            if(c1[j]=='k' && c1[j+1]=='w' && c1[j+3]!='r')
            {
                int temp = 0;
                char a[15],b[15],val[13];
                j+=3;
                while(c1[j]!=']')
                {
                    a[temp++] = c1[j++];
                }
                a[temp] = '\0';
                j+=2;
                if(c1[j]=='[' && c1[j+1]=='i' && c1[j+2]=='d' && c1[j+3]==' ' )
                {
                    j+=4;
                    temp = 0;
                    while(c1[j]!=']')
                    {
                        b[temp++] = c1[j++];
                    }
                    b[temp] = '\0';

                    j+=3;
                    if(c1[j]=='s' || c1[j]=='o')
                    {
                        if(c1[j]=='s') insert(b,a,"var",scp,"0");
                        else
                        {
                            j+=10;
                            temp=0;
                            while(c1[j]!=']')
                            {
                                val[temp++] = c1[j++];
                            }
                            val[temp] = '\0';
                            insert(b,a,"var",scp,val);
                        }
                    }

                    else
                    {
                        j+=4;
                        if(c1[j]==')')
                        {
                            insert(b,a,"var",scp,"0");
                        }
                        else{
                            insert(b,a,"func","global"," ");
                            strcpy(scp,b);
                        }

                    }
                }

            }


            else if(c1[j]=='[' && c1[j+1]=='i' && c1[j+2]=='d' && c1[j+3]== ' ')
            {

                char b[15],val[13];
                j+=4;
                int temp = 0;
                while(c1[j]!=']')
                {
                    b[temp++] = c1[j++];
                }
                b[temp] = '\0';

                j+=3;
                if(c1[j]=='o' && c1[j+7]=='n')
                {
                    j+=10;
                    temp=0;
                    while(c1[j]!=']')
                    {
                        val[temp++] = c1[j++];

                    }
                    val[temp] = '\0';

                    set_attribute(b,scp,val);
                }

            }

        }

        display();
    }

    return 0;
}




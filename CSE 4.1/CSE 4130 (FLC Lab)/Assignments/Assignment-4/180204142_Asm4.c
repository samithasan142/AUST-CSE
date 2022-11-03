
/* CSE 4130 (Fall 2021)                  Assignment - 4                   ID:180204142           */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX 20

char inS[];
char kwString[100];
char var[10];
int row=0;

char a3[10000],b3[10000],temp3[10000],c3[1000][100];
int inde[10000];
int cur = 0;
struct data
{
    char * name;
    char * idType;
    char* dataType;
    char* scope;
    char* value;

}v[100];

void insert(int ind,char* _name, char* _id,char* _dat,char* _scope,char* _value)
{
    v[ind].name  =_name;
    v[ind].idType= _id;
    v[ind].dataType = _dat;
    v[ind].scope  =_scope;
    v[ind].value  =_value;
}

void display()
{
    int i=0;
    printf("\nSl. No.\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n");
    for(i=0;i<cur;i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",i+1,v[i].name,v[i].idType,v[i].dataType,v[i].scope,v[i].value);
    }
}

int search(char* _name,char* _id,char* _scope)
{
    int i=0;

    for(i=0;i<cur;i++)
    {
        if(strcmp(v[i].name,_name)==0 && strcmp(v[i].idType,_id)==0 && strcmp(v[i].scope,_scope)==0 )
        {
            return i;
        }
    }
    return -1;
}

char* modify(char * x)
{
    if(strlen(x)==0)
        return x;
    if(x[0]>='0' && x[0]<='9')
        return x;
    return "";
}

void update(int cur,char* val)
{
    v[cur].value  = val;
}

int keyword(char *arr)
{
    if(strcmp("char", arr)==0||strcmp("int", arr)==0||strcmp("float", arr)==0||strcmp("string", arr)==0||strcmp("include", arr)==0
            ||strcmp("if", arr)==0||strcmp("else", arr)==0||strcmp("for", arr)==0||strcmp("while", arr)==0||strcmp("do", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int op(char *arr)
{
    if(strcmp("=", arr)==0||strcmp("+", arr)==0||strcmp("-", arr)==0||strcmp("*", arr)==0||strcmp("/", arr)==0
            ||strcmp("<=", arr)==0||strcmp(">=", arr)==0||strcmp("<", arr)==0||strcmp(">", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int sep(char *arr)
{
    if(strcmp(",", arr)==0||strcmp(";", arr)==0||strcmp("\'", arr)==0||strcmp("\"", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int par(char *arr)
{
    if(strcmp("(", arr)==0||strcmp(")", arr)==0||strcmp("{", arr)==0||strcmp("}", arr)==0||strcmp("[", arr)==0||strcmp("]", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int num(char *arr,int len)
{
    int flag=0;
    for(int i=0; i<len; i++)
    {
        if(isdigit(arr[i])!=0||arr[i]=='.')
        {
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int id(char *arr,int len)
{
    int flag=0;
    if(arr[0]=='_'||isalpha(arr[0])!=0)
    {
        for(int i=1; i<len; i++)
        {
            if(isdigit(arr[i])!=0||isalpha(arr[i])!=0||arr[i]=='_')
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
    else
    {
        return 0;
    }

}

int findOpSepImmediateOutput()
{
    FILE *token, *token2;
    token = fopen("token.txt","a");
    token2 = fopen("token2.txt","a");
    int i=0;
    if (inS[0]=='+' || inS[0]=='-' || inS[0]=='/' || inS[0]=='%' || inS[0]=='*' || inS[0]=='=' || inS[0]=='>'||inS[0]=='<' ||inS[0]=='&'||inS[0]=='!'||inS[0]=='|' ||inS[0]=='^')
    {
        fprintf(token,"%s",inS);
        fprintf(token2,"[%s]",inS);
        i=1;
    }
    else if(inS[0]=='(' ||inS[0]==')' ||inS[0]=='{' ||inS[0]=='}' ||inS[0]=='[' ||inS[0]==']')
    {
        i=1;
        fprintf(token,"%s",inS);
        fprintf(token2,"[%s]",inS);
    }
    else if (inS[0]==',' ||inS[0]==';' || inS[0]=='\'' ||inS[0]=='"' )
    {
        fprintf(token,"%s",inS);
        fprintf(token2,"[%s]",inS);
        i=1;
    }
    fclose(token2);
    fclose(token);
    return i;

}

int findNumericExImmediateOutput()
{
    FILE *token, *token2;
    token = fopen("token.txt","a");
    token2 = fopen("token2.txt","a");
    int s=0;
    int i=0,l;
    l=strlen(inS);
    if(isdigit(inS[0]))
    {
        s=1;
        i++;
    }
    else if(inS[0]=='.')
    {
        s=2;
        i++;
    }
    else
    {
        s=0;
    }

    if(s==1)
    {
        for(; i<l; i++)
        {
            if(isdigit(inS[i]))
            {
                s=1;
            }
            else if(inS[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }
    }
    if(s==2)
    {
        if(isdigit(inS[i]))
        {
            s=3;
            i++;
        }
        else
        {
            s=0;
        }
    }
    if(s==3)
    {
        for(; i<l; i++)
        {
            if(isdigit(inS[i]))
            {
                s=3;
            }
            else
            {
                s=0;
                break;
            }
        }
    }

    if(s==3)
    {
        s==1;
    }
    if(s)
    {
        fprintf(token,"%s",inS);
        fprintf(token2,"[%s]",inS);
    }

    fclose(token);
    fclose(token2);
    return s;

}

int findVariableImmediateOutput()
{
    FILE *token, *token2;
    token = fopen("token.txt","a");
    token2 = fopen("token2.txt","a");
    int i=0,s=0,l;
    l=strlen(inS);
    if(isalpha(inS[0]) || inS[0]=='_')
    {
        s=1;
        i++;
    }
    else
    {
        s=0;
    }
    if(s==1)
    {
        for(; i<l; i++)
        {
            if(inS[i]=='_' || isalnum(inS[i]))
            {
                s=1;
            }
            else
            {
                s=0;
                break;
            }
        }
    }
    if(s)
    {
        fprintf(token," id %s ",inS);
        fprintf(token2,"[%s]",inS);
    }

    fclose(token);
    fclose(token2);
    return s;
}

int findKeywordsImmediateOutput()
{
    FILE *token, *token2;
    token = fopen("token.txt","a");
    token2 = fopen("token2.txt","a");
    int i=0;
    FILE *p1;
    p1 = fopen("Ckeywords.txt","r");

    while(fgets(kwString, 100, p1))
    {
        strtok(kwString, "\n");
        if(!strcmp(inS,kwString))
        {
            i=1;
            fprintf(token,"%s ",inS);
            fprintf(token2,"[%s]",inS);

        }
        else
        {
            continue;
        }
    }
    fclose(token);
    fclose(token2);
    return i;
}

void filterforIntermidiateOutput()
{
    FILE *in, *out;
    char x,x1,c;
    in = fopen("a1.txt","r");
    out = fopen("filterIO.txt","w");

    while((x = fgetc(in))!=EOF)
    {

        if(x=='\n' || x=='\t')
        {
            if(x=='\n')
            {
                fputc(x,out);
            }
            continue;

        }
        if(x==' ')
        {

            x1=fgetc(in);

            if(x1==' ' || x1=='\n')
            {
                continue;
            }
            else if(x1=='/')
            {
                x=x1;
            }
            else
            {
                fputc(x,out);
                x=x1;
            }
        }

        if(x=='/')
        {
            x1= fgetc(in);
            if(x1=='/')
            {
                while((x1=fgetc(in))!=EOF)
                {
                    if(x1=='\n')
                    {
                        break;
                    }
                }
                continue;
            }
            else if(x1=='*')
            {
                while((x=fgetc(in))!=EOF)
                {
                    if(x=='*')
                    {
                        x=fgetc(in);
                        if(x=='/')
                            break;
                    }
                }
                continue;
            }

        }
        if(x=='"')
        {
            fputc(x,out);
            while((x1=fgetc(in))!=EOF )
            {
                fputc(x1,out);
                if(x1=='"')
                {
                    break;
                }

            }
        }
        else
        {
            fputc(x,out);
        }
    }

    fclose(in);
    fclose(out);

    FILE *token, *token2;
    in = fopen("filterIO.txt","r");
    out = fopen("out.txt","w");
    token = fopen("token.txt","w");
    token2= fopen("token2.txt","w");
    fclose(token);
    fclose(token2);

    char c1;

    while((c=fgetc(in))!=EOF)
    {
        if(c=='<'||c=='>'||c=='=' ||c=='!' || c=='+' ||c=='-'||c=='*'||c=='/'||c=='|'||c=='&')
        {
            c1=c;
            c=fgetc(in);
            if(c=='='||c=='+'||c=='-'||c=='|'|| c=='&'||c=='<'||c=='>')
            {
                fputc(' ',out);
                fputc(c1,out);
                fputc(c,out);
                fputc(' ',out);
                continue;
            }
            else
            {
                fputc(' ',out);
                fputc(c1,out);
                fputc(' ',out);
            }
        }
        if(isalpha(c) || c=='_' || c==' ' || isdigit(c)|| c=='.')
        {

            fputc(c,out);
        }
        else
        {
            fputc(' ',out);
            fputc(c,out);
            fputc(' ',out);
        }
    }

    fclose(out);

    out = fopen("out.txt","r");
    int i = 0;
    int len=0;

    while((x=fgetc(out))!=EOF)
    {
        if(x==' ')
        {
            len = i;
            if(len>0)
            {
                int foundOpSep = findOpSepImmediateOutput();

                if(!foundOpSep)
                {
                    int foundKw = findKeywordsImmediateOutput();

                    if(!foundKw)
                    {
                        int foundNx= findNumericExImmediateOutput();

                        if(!foundNx)
                        {
                            int foundVar = findVariableImmediateOutput();
                            if (x=='\n')
                            {
                                token = fopen("token.txt","a");
                                fprintf(token,"\n%s",inS);
                                fclose(token);
                                token2 = fopen("token2.txt","a");
                                fprintf(token2,"[%s]",inS);
                                fclose(token2);
                                continue;
                            }

                            if(!foundVar)
                            {
                                token = fopen("token.txt","a");
                                fprintf(token," %s",inS);
                                fclose(token);
                                token2 = fopen("token2.txt","a");
                                fprintf(token2,"[%s]",inS);
                                fclose(token2);
                            }

                        }
                    }
                }
            }

            i=0;
            len=0;
            strcpy(inS, "");
        }
        else
        {
            strncat(inS, &x, 1);
            i++;
        }
    }
    fclose(out);
}

void AddLineNo()
{
    FILE *p1, *p2;
    int count=1;
    char x;
    int newline=1;
    p1 = fopen("token.txt", "r");
    p2 = fopen("IntermediateOutput.txt","w");

    while((x = fgetc(p1))!= EOF)
    {
        if(newline)
        {
            fprintf(p2, "%d",count);
            fputc(' ', p2);
            newline=0;
        }
        fputc(x, p2);
        if (x=='\n')
        {
            count++;
            fputc('\n', p2);
            fprintf(p2, "%d",count);
            fputc(' ', p2);
        }
    }
    fclose(p1);
    fclose(p2);
}

struct stack
{
    char stk[MAX];
    int top;
} s;

void push(char item)
{
    if (s.top == (MAX - 1))
        printf ("Stack is Full\n");
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = item;
    }
}

void pop()
{
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1;
    }
}

struct HashTable
{
    char name[100],Id_type[100],data_type[20],scope[100],value[100];
} tableRow[100];


void ParanthesisProblem()
{
    char exp[100];
    char *ptr;
    long ret;
    int i = 0;
    s.top = -1;

    FILE *f1;
    f1 = fopen("IntermediateOutput.txt","r");


    while(fgets(exp, 100, f1))
    {
        if(!strcmp(exp,"\n"))
        {
            continue;
        }
        strtok(exp, "\n");
        ret = strtol(exp, &ptr, 10);

        for(i = 0; i<strlen(exp); i++)
        {
            if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            {
                push(exp[i]);
                continue;
            }
            else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
            {
                if(exp[i] == ')')
                {
                    if(s.stk[s.top] == '(')
                    {
                        pop();
                    }
                    else
                    {
                        printf("\nUnbalanced \')\' at line %ld\n",ret);
                        break;
                    }
                }
                if(exp[i] == ']')
                {
                    if(s.stk[s.top] == '[')
                    {
                        pop();
                    }
                    else
                    {
                        printf("\nUnbalanced \']\' at line %ld\n\n");
                        break;
                    }
                }
                if(exp[i] == '}')
                {
                    if(s.stk[s.top] == '{')
                    {
                        pop();
                    }
                    else
                    {
                        printf("\nUnbalanced \'}\' at line %ld\n",ret);
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
    fclose(f1);
}

void CheckIfElse()
{
    char exp[100];
    char *ptr;
    long ret;
    int i = 0;
    s.top = -1;

    strcpy(s.stk,"");

    FILE *f1;
    f1 = fopen("IntermediateOutput.txt","r");

    while(fgets(exp, 100, f1))
    {
        if(!strcmp(exp,"\n"))
        {
            continue;
        }
        strtok(exp, "\n");
        ret = strtol(exp, &ptr, 10);

        for(i = 0; i<strlen(exp); i++)
        {
            if(exp[i]=='i')
            {
                if(exp[i+1]=='f')
                {
                    push(exp[i]);
                    i = i+1;
                    continue;
                }
            }
            else if(exp[i]=='e')
            {
                if(exp[i+1]=='l')
                {
                    if(exp[i+2]=='s')
                    {
                        if(exp[i+3]=='e')
                        {
                            if(s.stk[s.top] == 'i')
                            {
                                pop();
                            }
                            else
                            {
                                printf("\nUnmatched \'else\' at line %ld\n",ret);
                                break;
                            }
                            i=i+3;
                        }
                    }
                }
            }
            else
            {
                continue;
            }
        }

    }
    fclose(f1);
}

void CheckDuplicateSep()
{

    char exp[100];
    char *ptr;
    long ret;
    int i = 0,j=0,n=0;

    FILE *f1;
    f1 = fopen("IntermediateOutput.txt","r");


    while(fgets(exp, 100, f1))
    {

        if(!strcmp(exp,"\n"))
        {
            continue;
        }

        strtok(exp, "\n");

        ret = strtol(exp, &ptr, 10);

        for(i=0; i<strlen(exp); i++)
        {
            if(exp[i]=='f')
            {
                if(exp[i+1]=='o')
                {
                    if(exp[i+2]=='r')
                    {

                        j=i+2;
                        while(exp[j]!=')' && j<strlen(exp))
                        {
                            j++;
                            continue;
                        }
                        i=j;
                        continue;
                    }
                }
            }

            if(exp[i]==';')
            {
                j=i+1;
                while(exp[j]==';' && j<strlen(exp))
                {
                    j++;
                    n=1;
                    continue;
                }
                i=j;
            }
            else
            {
                continue;
            }
            if(n)
            {
                printf("\nDuplicate Token at line %ld\n",ret);
            }
            n=0;

        }
    }
    fclose(f1);
}

bool FindValue(char* value)
{
    int x=0;
    int position=0;
    while(value[x]!='\0')
    {
        if(!(isdigit(value[x]) || value[x]=='.'))
        {
            return false;
        }
        if(value[x]=='.')
        {
            position++;
            if(position>1)
                return false;
        }
        x++;
    }
    return true;
}

int Search(char* idname,char* scope)
{
    int i;
    for(i=0; i<row; i++)
    {
        if(!strcmp(tableRow[i].name,idname) && !strcmp(tableRow[i].scope,scope))
        {
            return i;
        }
    }
    return -1;
}

bool DataTypes(char* s)
{

    if((!strcmp(s, "int")) || (!strcmp(s, "float")) || (!strcmp(s, "double")) ||(!strcmp(s, "char"))||(!strcmp(s, "bool")))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void take()
{
    FILE *f1;
    f1 = fopen("tokenFINAL.txt", "r");
    char scope[10],Type[20],Name[100],Value[100];

    bool flag= false;
    char c,c1,c2,c3;
    int x=0;

    strcpy(scope,"global");


    while(fgetc(f1)!=EOF)
    {
        x=0;
        while((c=fgetc(f1))!=']')
        {
            Type[x++]=c;

        }
        Type[x]='\0';

        if(!DataTypes(Type))
        {

            if(!strcmp(Type,"}"))
            {
                strcpy(scope,"global");
            }
            if(Type[0]=='i' && Type[1]=='d')
            {
                flag=true;
            }
            else
            {
                continue;
            }

        }
        if(!flag)
        {
            fgetc(f1);
            fgetc(f1);
            fgetc(f1);
            fgetc(f1);
            x=0;

            while((c=fgetc(f1))!=']')
            {
                Name[x++]=c;
            }
            Name[x]='\0';
        }
        else
        {

            x=3;

            while(Type[x]!='\0')
            {
                Name[x-3]=Type[x];
                x++;
            }
            Name[x-3]='\0';

        }

        fgetc(f1);
        c=fgetc(f1);

        if(!strcmp(Name,"main"))
        {
            strcpy(scope,"global");
        }
        if(c=='=')
        {
            fgetc(f1);
            fgetc(f1);

            x=0;

            while((c=fgetc(f1))!=']')
            {
                Value[x++]=c;
            }
            Value[x]='\0';
            fgetc(f1);
            fgetc(f1);
            fgetc(f1);


            if(!FindValue(Value))
            {
                continue;
            }

            int NewRow= Search(Name,scope);

            if(NewRow==-1)
            {
                strcpy(tableRow[row].name,Name);
                strcpy(tableRow[row].Id_type,"var");
                strcpy(tableRow[row].data_type,Type);
                strcpy(tableRow[row].scope,scope);
                strcpy(tableRow[row].value,Value);
                row++;
            }
            else
            {
                strcpy(tableRow[NewRow].value,Value);
            }
        }


        else if(c=='(')
        {
            fgetc(f1);
            strcpy(tableRow[row].name,Name);
            strcpy(tableRow[row].Id_type,"func");
            strcpy(tableRow[row].data_type,Type);
            strcpy(tableRow[row].scope,scope);
            strcpy(tableRow[row].value,"");
            strcpy(scope,Name);
            row++;
        }
        else
        {
            if(!flag)
            {
                fgetc(f1);
                strcpy(tableRow[row].name,Name);
                strcpy(tableRow[row].Id_type,"var");
                strcpy(tableRow[row].data_type,Type);
                strcpy(tableRow[row].scope,scope);
                strcpy(tableRow[row].value,"");
                row++;
            }
        }
        flag=false;
    }
    fclose(f1);
}

void searchTable()
{
    int i;
    for(i=0; i<row; i++)
    {
        char s[20];
        strcpy(s,tableRow[i].data_type);
        if((!strcmp(s, "int")) || (!strcmp(s, "float")) || (!strcmp(s, "double")) ||(!strcmp(s, "char"))||(!strcmp(s, "bool")))
        {
            continue;

        }
        else
        {
            printf("\nUndeclared Identifier %s\n",tableRow[i].name);
        }
    }
    int j,k;
    char s1[20],s2[20];
    for(i=0; i<row; i++)
    {

        strcpy(s1,tableRow[i].name);
        strcpy(s2,tableRow[i].scope);
        k=i;
        for(j=0; j<row; j++)
        {
            if(j==k)
            {
                continue;
            }
            if(!(strcmp(s1,tableRow[j].name)) && !(strcmp(s2,tableRow[j].scope)))
            {
                    printf("\nDuplicate Identifier %s\n",tableRow[i].name);
            }
        }

    }


    return;
}

int main()
{
    FILE *p0,*p1,*p2,*p3,*p4;
    char d;
    char t[9999];
    int i=0;
    int f = 0;
    p0=fopen("a1.txt","w");
    while(scanf("%c",&d))
    {
        if(d == '$')
        {
            break;
        }
        else{
            fputc(d,p0);
            t[i] = d;
            i++;
            f++;
        }

    }
    fclose(p0);
    char nt[9999];
    int b = 0;

    for(int i=0; i<f; i++)
    {
        if(t[i] == '/' && t[i+1] == '/')
        {
            while(t[i] != '\n')
            {
                i++;
            }
        }

        if(t[i] == '/' && t[i+1] == '*')
        {
            i=i+2;
            while(1)
            {
                if(t[i]=='*'&&t[i+1]=='/')
                {
                    break;
                }
                i++;
            }
            i=i+2;
        }
        nt[b]=t[i];
        b++;
    }

    char nt1[b];
    int cnt = 0;
    for(int i=0; i<b; i++)
    {
        if(nt[i] != '\n')
        {
            nt1[cnt] = nt[i];
            cnt++;
        }

    }
    p1=fopen("a2.txt","w");
    int k=0;
    while(k<cnt)
    {
        fputc(nt1[k],p1);
        k++;
    }
    fclose(p1);

    p1=fopen("a2.txt","r");
    char c;

    p1=fopen("a2.txt","r");
    p2=fopen("temp.txt","w");
    while((c=fgetc(p1))!=EOF)
    {
        if(c==';'||c==','||c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']'||c=='+'||c=='-'||c=='*'||c=='/')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='\''||c=='\"')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='=')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(c,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc('=',p2);
                fputc(' ',p2);
                if(c=='\''||c=='\"')
                {
                    fputc(c,p2);
                    fputc(' ',p2);
                }
                else
                    fputc(c,p2);
            }
        }
        else if(c=='!')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc('!',p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
        }
        else if(c=='<'||c=='>')
        {
            char prev=c;
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(' ',p2);
                fputc(c,p2);
            }
        }
        else
        {
            fputc(c,p2);
        }

    }
    fclose(p1);
    fclose(p2);
    p2=fopen("temp.txt","r");
    p3=fopen("temp2.txt","w");
    while((c=fgetc(p2))!=EOF)
    {
        if(c==' ')
        {
            while((c=fgetc(p2))==' ');
            fputc(' ',p3);
            fputc(c,p3);
        }
        else
            fputc(c,p3);
    }
    fclose(p2);
    fclose(p3);

    p3=fopen("temp2.txt","r");
    p4=fopen("final.txt","w");
    char ar[100];
    int index=0;
    while((c=fgetc(p3))!=EOF)
    {
        ar[index++]=c;
        while((c=fgetc(p3))!=' ')
        {
            ar[index++]=c;
        }
        ar[index]='\0';

        fputc('[',p4);
        int state=keyword(ar);
        if(!state)
        {
            state=op(ar);
            if(!state)
            {
                state=sep(ar);
                if(!state)
                {
                    state=par(ar);
                    if(!state)
                    {
                        state=num(ar,index);
                        if(!state)
                        {
                            state=id(ar,index);
                            if(!state)
                            {
                                fputs("unkn",p4);
                            }
                            else
                                fputs("id",p4);

                        }
                        else
                            fputs("num",p4);
                    }
                    else
                        fputs("par",p4);
                }
                else
                    fputs("sep",p4);
            }
            else
                fputs("op",p4);
        }
        else
            fputs("kw",p4);

        fputc(' ',p4);
        fputs(ar,p4);
        fputc(']',p4);
        index=0;
        memset(ar, 0, sizeof(ar));

    }
    fclose(p3);
    fclose(p4);

    int j;
    FILE* fp = fopen("final.txt","r");
    i =0;
    while(fscanf(fp,"%c",&a3[i])!=EOF)
    {
        i++;
    }
    a3[i]  = '\0';
    fclose(fp);
    printf("Processed Input: \n");
    puts(a3);
    k  =0;
    for(i=0;i<strlen(a3);i++)
    {
        if(a3[i]=='[')
        {
            b3[k++]  = a3[i++];
            j = 0;
            while(a3[i]!=' ')
            {
                temp3[j++]  = a3[i];
                i++;

            }
            temp3[j]  = '\0';
            if(strcmp(temp3,"id")==0)
            {
                b3[k++]  = 'i';
                b3[k++]  = 'd';
                b3[k++]  = ' ';
            }
            i++;
            while(a3[i]!=']')
            {
                b3[k++]  = a3[i];
                i++;

            }
            b3[k++] =  a3[i];

        }
    }
    b3[k]  = '\0';
    printf("\nStep 1: \n");
    puts(b3);
    fp = fopen("A3_O1.txt","w");
    fputs(b3,fp);
    fclose(fp);


    printf("\n\n\nIntermediate Output : \n");
    filterforIntermidiateOutput();
    AddLineNo();
    FILE *m;
    m=fopen("IntermediateOutput.txt","r");
    while((c=fgetc(m))!=EOF)
    {
        printf("%c",c);
    }
    fclose(m);

    printf("\n\nErrors : \n");

    ParanthesisProblem();
    CheckIfElse();
    CheckDuplicateSep();

    take();

    searchTable();

    return 0;
}

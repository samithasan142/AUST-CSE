
/* CSE 4130 (Fall 2021)                  Assignment - 2                   ID:180204142   */

#include <stdio.h>
#include <string.h>

void lexemeSeparator(FILE *source, FILE *target, char inputFile[30], char targetFile[30]);
void lexemeTokenization(FILE *source, FILE *target, char inputFile[30], char targetFile[30]);
int isKeyword(char *lex);
int isIdentifier(char *lex);
int isSeparator(char *lex);
int isNumerical(char *lex);
int isOperator(char *lex);
int isParenthesis(char *lex);

int main()
{
    char c;
    char inputFile[30] = "Input_Asm2.txt";
    char tempFile[30] = "LexemeSeparatedTemp.txt";
    char targetFile[30] = "Output_Asm2.txt";
    FILE *source, *target, *temp;

    // Lexeme separator
    source = fopen(inputFile, "r");
    temp = fopen(tempFile, "w");
    lexemeSeparator(source, temp, inputFile, tempFile);

    //  Lexeme Categorizer
    temp = fopen(tempFile, "r");
    target = fopen(targetFile, "w");
    lexemeTokenization(temp, target, tempFile, targetFile);

    target = fopen (targetFile,"r");
    while( (c = fgetc(target)) != EOF)
    {
        printf("%c",c);
    }
    fclose(target);

    remove(tempFile);
    remove(targetFile);
    printf("\n\n");
    return 0;
}

void lexemeSeparator(FILE *source, FILE *target, char inputFile[30], char targetFile[30])
{
    char c;
    int lexemeStart = 0;
    char tempFile[30] = "temp1.txt";
    FILE *temp;
    temp = fopen(tempFile, "w");
    if(source == NULL || target == NULL || temp == NULL){
        printf("\nFile cannot be opened");
    }
    else{
        while( (c = fgetc(source)) != EOF ){
            if(c == ' '){
                fputc(c,temp);
                lexemeStart = 0;
                continue;
            }
            if(c != ' ' && lexemeStart == 0)
            {
                lexemeStart = 1;
            }
            if(lexemeStart == 1){
                if(c == ';' || c == ',' || c == 39 || c == '+' || c == '-' ||
                   c == '*' || c == '/' || c == '%' || c == '(' || c == ')')   //apostrophe ascii = 39
                {
                    fputc(' ',temp);      //leading space of the lexeme
                    fputc(c,temp);
                    lexemeStart = 0;
                    char cc = fgetc(source);
                    if (cc == '+' || cc == '-' ){
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }
                    else if (cc == ';')   //semicolon after apostrophe
                    {
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }
                    else
                    {
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                    }
                    continue;
                }
                else if(c == '>' || c == '<' || c == '!' || c == '|' || c == '&' || c == '='){
                    fputc(' ',temp);      //leading space of the lexeme
                    fputc(c,temp);
                    lexemeStart = 0;
                    char cc = fgetc(source);
                    if (cc == '=' || cc == '|' || cc == '&')    //for checking  >=  <=  !=  &&  ||
                    {
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }
                    else if (cc == 39)      //apostrophe ASCII = 39
                    {
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                        fputc(' ',temp);  //trailing space of the lexeme
                    }
                    else
                    {
                        fputc(' ',temp);  //leading space of the lexeme
                        fputc(cc,temp);
                    }
                    continue;
                }
                fputc(c,temp);
            }
        }
    }
    fputc(' ',temp);
    fclose(source);
    fclose(temp);

    //Removing more than one spaces
    int syntaxSpace = 0;
    int codeStart = 0;
    source = fopen(tempFile, "r");

    while( (c = fgetc(source)) != EOF )
    {
        if(c == 32 && syntaxSpace == 0 && codeStart == 1)           //one space between syntaxes
        {
            fputc(32,target);
            syntaxSpace = 1;
            continue;
        }
        else if(c == 32 && syntaxSpace == 1 && codeStart == 1)      //more than one space between syntaxes
        {
            continue;
        }
        else if(c != 32)                                            //any character other than space
        {
            fputc(c,target);
            codeStart = 1;
            syntaxSpace = 0;
        }
    }
    fclose(source);
    fclose(target);
    remove(tempFile);
}

void lexemeTokenization(FILE *source, FILE *target, char inputFile[30], char targetFile[30])
{
    char c, lex[50];
    if(source == NULL || target == NULL){
        printf("\nFile cannot be opened");
    }
    else
    {
        int i = 0;
        while( (c = fgetc(source)) != EOF )
        {
            if(c == ' ')        //checking each lexeme separately and putting them in target file
            {
                lex[i] = '\0';
                i=0;
                if(isSeparator(lex))
                {
                    fputs("[sep ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isParenthesis(lex))
                {
                    fputs("[par ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isOperator(lex))
                {
                    fputs("[op ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isNumerical(lex))
                {
                    fputs("[num ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isKeyword(lex))
                {
                    fputs("[kw ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else if(isIdentifier(lex))
                {
                    fputs("[id ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                else
                {
                    fputs("[unkn ", target);
                    fputs(lex, target);
                    fputs("] ", target);
                }
                continue;
            }
            else{
                lex[i] = c;
                i++;
            }
        }
    }
    fclose(source);
    fclose(target);
}

int isNumerical(char *lex)
{
    int i, l, s;
    i=0;
    if(isdigit(lex[i])){
        s=1;
        i++;
    }
    else if(lex[i]=='.'){
        s=2;
        i++;
    }
    else
        s=0;

    l=strlen(lex);
    if(s==1){
        for(; i<l; i++){
            if(isdigit(lex[i]))
                s=1;
            else if(lex[i]=='.'){
                s=2;
                i++;
                break;
            }
            else{
                s=0;
                break;
            }
        }
    }
    if(s==2){
        if(isdigit(lex[i])){
            s=3;
            i++;
        }
        else
            s=0;
    }
    if(s==3){
        for(; i<l; i++){
            if(isdigit(lex[i]))
                s=3;
            else{
                s=0;
                break;
            }
        }
    }
    if(s==3){
        s=1;
    }
    return s;
}

int isSeparator(char *lex)
{
    int s = 0 ;

    if( lex[0] == ';' || lex[0] == ',' || lex[0] == 39 ){
        s = 1;
    }
    return s;
}

int isParenthesis(char *lex)
{
    int s = 0 ;

    if( lex[0] == '(' || lex[0] == ')' || lex[0] == '{' || lex[0] == '}' ){
        s = 1;
    }
    return s;
}

int isOperator(char *lex)
{
    int s = 0 ;

    if(strlen(lex) == 1)
    {
        if( lex[0] == '+' || lex[0] == '-' || lex[0] == '*' || lex[0] == '/' || lex[0] == '%' ||
            lex[0] == '=' || lex[0] == '<' || lex[0] == '>' || lex[0] == '!' || lex[0] == '&' ||
            lex[0] == '|' || lex[0] == '~' || lex[0] == '^' )
        {
            s = 1;
        }
    }
    if(strlen(lex) == 2)
    {
        if( (lex[0] == '+' && lex[1] == '+') || (lex[0] == '-' && lex[1] == '-') || (lex[0] == '=' && lex[1] == '=') ||
            (lex[0] == '!' && lex[1] == '=') || (lex[0] == '|' && lex[1] == '|') || (lex[0] == '&' && lex[1] == '&') ||
            (lex[0] == '>' && lex[1] == '=') || (lex[0] == '<' && lex[1] == '=') )
        {
            s = 1;
        }
    }
    return s;
}

int isIdentifier(char *lex)
{
    int s = 0 ;

    if((lex[0] >= 'a' && lex[0] <= 'z') || (lex[0] >= 'A' && lex[0] <= 'Z') || lex[0] == '_' )
    {
        s = 1;      //checking first character if it's valid or not (a-z) || (A-Z) || _
    }

    if (s==0)
        return s ;
    else
    {
        int i;
        for ( i = 1 ; i<strlen(lex); i++){
            if((lex[i] >= 'a' && lex[i] <= 'z') || (lex[i] >= 'A' && lex[i] <= 'Z') ||
                lex[i] == '_' || (lex[i] >= '0' && lex[i] <= '9') )
            {
                continue;
            }
            else
            {
                s = 0;
            }
        }
    }
    return s ;
}

int isKeyword(char *lex)
{
    int s = 0 ;

    if(lex[0] == 'i' && lex[1] == 'n' && lex[2] == 't' )
    {
        s = 1;      //int
    }
    else if(lex[0] == 'c' && lex[1] == 'h' && lex[2] >= 'a' && lex[3] == 'r')
    {
        s = 1;      //char
    }
    else if(lex[0] == 'f' && lex[1] == 'l' && lex[2] >= 'o' && lex[3] == 'a' && lex[4] == 't')
    {
        s = 1;      //float
    }
    else if(lex[0] == 'd' && lex[1] == 'o' && lex[2] >= 'u' && lex[3] == 'b' && lex[4] == 'l' && lex[5] == 'e')
    {
        s = 1;      //double
    }
    else if(lex[0] == 'l' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 'g')
    {
        s = 1;      //long
    }
    else if(lex[0] == 's' && lex[1] == 'h' && lex[2] >= 'o' && lex[3] == 'r' && lex[4] == 't')
    {
        s = 1;      //short
    }
    else if(lex[0] == 'w' && lex[1] == 'h' && lex[2] >= 'i' && lex[3] == 'l' && lex[4] == 'e')
    {
        s = 1;      //while
    }
    else if(lex[0] == 'f' && lex[1] == 'o' && lex[2] >= 'r')
    {
        s = 1;      //for
    }
    else if(lex[0] == 'd' && lex[1] == 'o')
    {
        s = 1;      //do
    }
    else if(lex[0] == 'i' && lex[1] == 'f')
    {
        s = 1;      //if
    }
    else if(lex[0] == 'e' && lex[1] == 'l' && lex[2] >= 's' && lex[3] == 'e')
    {
        s = 1;      //else
    }
    else if(lex[0] == 'v' && lex[1] == 'o' && lex[2] >= 'i' && lex[3] == 'd')
    {
        s = 1;      //void
    }
    else if(lex[0] == 's' && lex[1] == 't' && lex[2] >= 'a' && lex[3] == 't' && lex[4] == 'i' && lex[5] == 'c')
    {
        s = 1;      //static
    }
    else if(lex[0] == 'b' && lex[1] == 'r' && lex[2] >= 'e' && lex[3] == 'a' && lex[4] == 'k')
    {
        s = 1;      //break
    }
    else if(lex[0] == 'c' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 't' && lex[4] == 'i' && lex[5] == 'n' && lex[6] == 'u' && lex[7] == 'e')
    {
        s = 1;      //continue
    }
    else if(lex[0] == 'd' && lex[1] == 'e' && lex[2] >= 'f' && lex[3] == 'a' && lex[4] == 'u' && lex[5] == 'l' && lex[6] == 't')
    {
        s = 1;      //default
    }
    else if(lex[0] == 'c' && lex[1] == 'o' && lex[2] >= 'n' && lex[3] == 's' && lex[4] == 't')
    {
        s = 1;      //const
    }
    else if(lex[0] == 's' && lex[1] == 'w' && lex[2] >= 'i' && lex[3] == 't' && lex[4] == 'c' && lex[5] == 'h')
    {
        s = 1;      //switch
    }
    else if(lex[0] == 'c' && lex[1] == 'a' && lex[2] >= 's' && lex[3] == 'e')
    {
        s = 1;      //case
    }
    else if(lex[0] == 's' && lex[1] == 'i' && lex[2] >= 'z' && lex[3] == 'e' && lex[4] == 'o' && lex[5] == 'f')
    {
        s = 1;      //sizeof
    }
    else if(lex[0] == 's' && lex[1] == 't' && lex[2] >= 'r' && lex[3] == 'u' && lex[4] == 'c' && lex[5] == 't')
    {
        s = 1;      //struct
    }
    else if(lex[0] == 's' && lex[1] == 'i' && lex[2] >= 'g' && lex[3] == 'n' && lex[4] == 'e' && lex[5] == 'd')
    {
        s = 1;      //signed
    }
    else if(lex[0] == 'u' && lex[1] == 'n' && lex[2] >= 's' && lex[3] == 'i' && lex[4] == 'g' && lex[5] == 'n' && lex[6] == 'e' && lex[7] == 'd')
    {
        s = 1;      //unsigned
    }
    else if(lex[0] == 'r' && lex[1] == 'e' && lex[2] >= 't' && lex[3] == 'u' && lex[4] == 'r' && lex[5] == 'n')
    {
        s = 1;      //return
    }
    else if(lex[0] == 'a' && lex[1] == 'u' && lex[2] >= 't' && lex[3] == 'o')
    {
        s = 1;      //auto
    }
    else if(lex[0] == 'e' && lex[1] == 'n' && lex[2] >= 'u' && lex[3] == 'm')
    {
        s = 1;      //enum
    }
    else if(lex[0] == 'e' && lex[1] == 'x' && lex[2] >= 't' && lex[3] == 'e' && lex[4] == 'r' && lex[5] == 'n')
    {
        s = 1;      //extern
    }
    else if(lex[0] == 'g' && lex[1] == 'o' && lex[2] >= 't' && lex[3] == 'o')
    {
        s = 1;      //goto
    }
    else if(lex[0] == 'r' && lex[1] == 'e' && lex[2] >= 'g' && lex[3] == 'i' && lex[4] == 's' && lex[5] == 't' && lex[6] == 'e' && lex[7] == 'r')
    {
        s = 1;      //register
    }
    else if(lex[0] == 'u' && lex[1] == 'n' && lex[2] >= 'i' && lex[3] == 'o' && lex[4] == 'n')
    {
        s = 1;      //union
    }
    else if(lex[0] == 't' && lex[1] == 'y' && lex[2] >= 'p' && lex[3] == 'e' && lex[4] == 'd' && lex[5] == 'e' && lex[6] == 'f')
    {
        s = 1;      //typedef
    }
    else if(lex[0] == 'v' && lex[1] == 'o' && lex[2] >= 'l' && lex[3] == 'a' && lex[4] == 't' && lex[5] == 'i' && lex[6] == 'l' && lex[7] == 'e')
    {
        s = 1;      //volatile
    }

    return s ;
}


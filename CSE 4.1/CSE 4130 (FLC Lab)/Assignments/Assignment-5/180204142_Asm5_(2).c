/* CSE 4130 (Fall 2021)                  Assignment - 5                   ID: 180204142   */
#include <stdio.h>
#include <string.h>

int index = 0;
char input[100];

int Exp();
int Term();
int Factor();
int NumID();


int NumID()
{
    if ((input[index] >= '0' && input[index] <= '9') && index < strlen(input))
    {
        index++;
        return 1;
    }

    if ((input[index] >= 'a' && input[index] <= 'e') && index < strlen(input))
    {
        index++;
        return 1;
    }

    return 0;
}

int Factor()
{
    if (NumID())
        return 1;

    if (input[index] == '(' && index < strlen(input))
    {
        index++;
        if (Exp())
        {
            if (input[index] == ')' && index < strlen(input))
            {
                index++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

int Term()
{
    if (Factor())
    {
        if ((input[index] == '*' || input[index] == '/') && index < strlen(input))
        {
            index++;
            if (Factor())
                return 1;

            return 0;
        }
        return 1;
    }
    return 0;
}

int Exp()
{
    if (Term())
    {
        if ((input[index] == '+' || input[index] == '-') && index < strlen(input))
        {
            index++;
            if (Term())
                return 1;

            return 0;
        }
        return 1;
    }
    return 0;
}

int main()
{
    printf("Enter the string : ");
    gets(input);

    if (Exp() && index==strlen(input))
        printf("String for CFG-2 is Accepted\n");
    else
        printf("String for CFG-2 is Rejected\n");

}

// 1+(2*3)
// 1*3-5/6
//(1+2)*(5+4)+(a-c)/(9-0)
//(1+2)*(3+4)-8*9

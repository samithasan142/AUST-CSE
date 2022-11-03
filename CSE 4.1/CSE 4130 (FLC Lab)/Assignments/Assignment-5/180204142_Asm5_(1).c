/* CSE 4130 (Fall 2021)                  Assignment - 5                   ID: 180204142   */
#include <stdio.h>
#include <string.h>

int index = 0;
char input[100];

int X()
{
    if (input[index] == 'b' && index < strlen(input))
    {
        index++;
        if ((input[index] == 'b' || input[index] == 'c') && index < strlen(input))
        {
            index++;
            if (X())
                return 1;

            return 0;
        }
        return 0;
    }
    return 1;
}
int A()
{
    if (input[index] == 'a' && index < strlen(input))
    {
        index++;
        if (X())
        {
            if (input[index] == 'd')
                return 1;
        }
        return 0;
    }
    return 0;
}

int main()
{
    printf("Enter the string : ");
    gets(input);

    if (A() && index + 1 == strlen(input))
        printf("String for CFG-1 is Accepted\n");
    else
        printf("String for CFG-1 is Rejected\n");
}

// abbbcbbd
// abcd
// abc
// ad
// abb
// abbd

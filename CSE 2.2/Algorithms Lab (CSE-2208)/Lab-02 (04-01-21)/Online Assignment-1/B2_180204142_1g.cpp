/*
    Linear search
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100], value, i, n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to search:\n");
    scanf("%d", &value);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("%d is found at location %d.\n", value, i+1);
            break;
        }
    }
    if (i == n)
    printf("%d is not present in the array.\n", value);

    return 0;
}

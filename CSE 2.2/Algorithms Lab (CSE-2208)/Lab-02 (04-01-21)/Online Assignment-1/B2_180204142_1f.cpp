/*
    Binary search
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, i, value, left, right, mid, arr[100];
    printf("Enter number of elements:\n");
    scanf("%d", &num);

    printf("Enter %d integers:\n", num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to search:\n");
    scanf("%d", &value);

    left=0;
    right=num-1;
    mid=(left+right)/2;

    while (left<=right)
    {
        mid=(left+right)/2;
        if(value==arr[mid])
        {
            printf("%d is found at location %d.\n", value, mid+1);
            break;
        }
        else if(value<arr[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }

    if(left>right)
    {
        printf("%d is not present in the array\n",value);
    }

    return 0;
}

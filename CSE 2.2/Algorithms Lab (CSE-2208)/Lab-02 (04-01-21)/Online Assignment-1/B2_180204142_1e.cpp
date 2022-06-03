/*
    Selection Sort
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100], n, i, j, minimum, t;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n-1; i++)
    {
        minimum = i;

        for (j = i+1; j < n; j++)
        {
            if (arr[minimum] > arr[j])
            {
                minimum = j;
            }
        }

        if (minimum != i)
        {
            /*t = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = t;*/
            swap(arr[minimum], arr[i]);
        }
    }

    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

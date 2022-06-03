/*
    Quick Sort
*/
#include<bits/stdc++.h>
using namespace std;

int part(int A[], int low, int high)
{
    int pivot, i,j;
    pivot=A[high];
    i=low-1;

    for(j=low; j<high; j++)
    {
        if(A[j]<pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[high]);

    return i+1;
}

void quick_sort(int A[], int low, int high)
{
    if(low>=high)
    {
        return;
    }

    int p=part(A, low, high);
    quick_sort(A, low, p-1);
    quick_sort(A, p+1, high);
}

int main()
{
    int i, n, A[100];
    //int A[]={1,5,6,3,8,4,7,2};

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    quick_sort(A,0,n);
    printf("Sorted list in ascending order:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}


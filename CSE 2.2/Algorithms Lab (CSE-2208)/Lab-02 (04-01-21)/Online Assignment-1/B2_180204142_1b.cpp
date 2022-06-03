/*
    Merge Sort
*/
#include<bits/stdc++.h>
using namespace std;

void mergee(int A[], int left, int mid,int right);

void merge_sort(int A[], int left, int right)
{
    if(left>=right)
    {
        return;
    }

    int mid=left+(right-left)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);
    mergee(A, left, mid, right);
}

void mergee(int A[], int left, int mid, int right)
{
    int i;
    int index_a, left_index, right_index;
    int size_left, size_right;

    size_left=mid-left+1;
    size_right=right-mid;

    int L[size_left],R[size_right];

    for(i=0; i<size_left; i++){
        L[i]=A[left+i];
    }

    for(i=0; i<size_right; i++){
        R[i]=A[mid+1+i];
    }
    left_index=0, right_index=0;

    for(index_a=left; left_index<size_left && right_index<size_right; index_a++)
    {
        if(L[left_index]<R[right_index])
        {
            A[index_a]=L[left_index];
            left_index++;
        }
        else{
            A[index_a]=R[right_index];
            right_index++;
        }
    }

    while(left_index<size_left)
    {
        A[index_a]=L[left_index];
        left_index++;
        index_a++;
    }

    while(right_index<size_right)
    {
        A[index_a]=R[right_index];
        right_index++;
        index_a++;
    }
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

    merge_sort(A,0,n);
    printf("Sorted list in ascending order:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}


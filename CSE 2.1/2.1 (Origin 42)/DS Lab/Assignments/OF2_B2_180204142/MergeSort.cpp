#include <bits/stdc++.h>
using namespace std;
void mergee(int a[], int left, int mid, int right);

void merge_sort(int a[], int left, int right)
{
    if(left>=right)
    {
        return;
    }
    int mid= left + (right-left)/2;

    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    mergee(a,left,mid,right);
}

void mergee(int a[], int left, int mid, int right)
{
    int i,j,n1,n2;
    n1=mid-left+1;
    n2=right-mid;

    int l[n1], r[n2];

    for(i=0; i<n1; i++)
    {
        l[i]=a[left+i];
    }

    for(j=0; j<n2; j++)
    {
        r[j]=a[mid+j+1];
    }

    i=0,j=0;

    for(int k=left; k<=right; k++)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i=i+1;
        }
        else
        {
            a[k]=r[j];
            j=j+1;
        }
    }
}

int main()
{
    int i, n=8;
    int a[]={1,5,6,3,5,8,7,2,9};
    merge_sort(a,0,n);

    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

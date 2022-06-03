#include<bits/stdc++.h>

int main()
{
    int ar[20],i,j,k,x,n,mid=0,high=0,low=0,temp=0,flag=0;

    printf("Enter the number of elements : \n");

    scanf("%d",&n);

    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("\nNow the elements are sorted in ascending order below (Using Bubble Sort): \n");

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n\nNow search for an element from the array using Binary Search: \n");
    scanf("%d",&x);

    high=n-1;
    low=0;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(ar[mid]>x)
        {
            high=mid-1;
        }
        else if(ar[mid]<x)
        {
            low=mid+1;
        }
        else if(ar[mid]==x)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        printf("\nThe element was found at position %d!\n",mid+1);
    }
    else printf("\nThe element was not found!\n");

}

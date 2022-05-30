#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[1005];
    int max, i;
    clock_t start_time, end_time;
    double bubble_time;

    printf("Enter the Upper bound: ");
    scanf("%d", &max);

    srand(time(0));
    for(i=0;i<1000;i++)
    {
        arr[i]=rand()%max+1;
    }

    start_time = clock();
    bubble_sort(arr,1000);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for bubble sort: %lf\n",bubble_time);

}


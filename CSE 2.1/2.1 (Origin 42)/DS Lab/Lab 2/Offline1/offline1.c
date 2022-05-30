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
    int arr[500005];
    int len, i;
    clock_t start_time, end_time;
    double bubble_time;

    printf("Enter Array Length: ");
    scanf("%d", &len);

    srand(time(0));
    for(i=0;i<len;i++)
    {
        arr[i]=rand()%100+1;
    }

    start_time = clock();
    bubble_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for bubble sort: %lf\n",bubble_time);

}

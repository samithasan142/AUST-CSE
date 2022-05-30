#include<bits/stdc++.h>
using namespace std;

int arr[500005],arr2[500005],arr3[500005],arr4[500005];
long long swap_counter=0,comp_counter=0;

void selection_sort(int n)
{
    int i,j,min_index,temp;

    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            comp_counter++;
            if(arr3[j]<arr3[min_index])
            {
                min_index = j;
            }
        }
        comp_counter++;
        if(min_index!=i)
        {
            temp = arr3[min_index];
            arr3[min_index]=arr3[i];
            arr3[i] = temp;
            swap_counter++;
        }
    }
}

void insertion_sort(int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr2[i];
        j = i - 1;
        while (j >= 0 && arr2[j] > key)
        {
            comp_counter++;
            arr2[j + 1] = arr2[j];
            j = j - 1;
            swap_counter++;;
        }
        arr2[j + 1] = key;
        swap_counter++;
    }
}

void bubble_sort(int n)
{
    int i,j,temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            comp_counter++;
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap_counter++;
            }
        }
    }
}

int main()
{
    int len, i;
    clock_t start_time, end_time;
    double bubble_time;

    printf("Enter Array Length: ");
    scanf("%d", &len);

    srand(time(0));
    for(i=0;i<len;i++)
    {
        arr[i]=rand()%100+1;
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    start_time = clock();
    bubble_sort(len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for bubble sort: %f\n",bubble_time);
    printf("Swap_counter = %lld, Comparision_counter = %lld\n\n",swap_counter,comp_counter);
    swap_counter=0;comp_counter=0;

    start_time = clock();
    selection_sort(len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for selection sort: %f\n",bubble_time);
    printf("Swap_counter = %lld, Comparision_counter = %lld\n\n",swap_counter,comp_counter);
    swap_counter=0;comp_counter=0;


    start_time = clock();
    insertion_sort(len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for insertion sort: %f\n",bubble_time);
    printf("Swap_counter = %lld, Comparision_counter = %lld\n\n",swap_counter,comp_counter);
    swap_counter=0;comp_counter=0;




}

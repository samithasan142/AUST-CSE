/*
    Heap Sort
*/
#include<bits/stdc++.h>
using namespace std;

void max_heapify(int heap[], int heap_size, int root)
{
    int largest = root;
    int left_child = 2 * root;
    int right_child = 2 * root + 1;

    if (left_child <= heap_size && heap[left_child] > heap[largest])
    {
        largest = left_child;
    }

    if (right_child <= heap_size && heap[right_child] > heap[largest])
    {
        largest = right_child;
    }

    if (largest != root)
    {
        swap(heap[root], heap[largest]);

        max_heapify(heap, heap_size, largest);
    }
}


void heapSort(int heap[], int heap_size)
{
    for (int root = heap_size / 2; root >= 1; root--)
    {
        max_heapify(heap, heap_size, root);
    }

    for (int root = heap_size; root > 1; root--)
    {
        swap(heap[1], heap[root]);
        heap_size--;
        max_heapify(heap, heap_size, 1);
    }
}

int main()
{
    int i, heap_size, heap[100];

    printf("Enter number of elements:\n");
    scanf("%d", &heap_size);

    printf("Enter %d integers:\n", heap_size);

    for (i = 1; i <= heap_size; i++)
    {
        scanf("%d", &heap[i]);
    }

    heapSort(heap, heap_size);

    printf("Sorted list in ascending order:\n");
    for (int root = 1; root <= heap_size; root++)
    {
        printf("%d ", heap[root]);
    }

    printf("\n");

    return 0;
}

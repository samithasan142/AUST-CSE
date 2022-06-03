#include<bits/stdc++.h>
using namespace std;

#define INF 999
int n;
int graph[100][100];
int matrix[100][100];

void floydWarshall();
void printMatrix();

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the matrix for %d nodes: \n", n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n\n");
    floydWarshall();
}

void floydWarshall()
{
    int i, j, k;
    int D[10][10][10];
    for (i = 0; i < n; i++)
    {
       for (j = 0; j < n; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

                D[k][i][j] = matrix[i][j];
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%3d  ", D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    printMatrix();
}

void printMatrix()
{
    printf("The shortest path matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("The shortest path between each pair are: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != INF && i!= j)
            {
                printf("[%d,%d] = %d\n", i+1, j+1, matrix[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            printf("Negative cycle detected");
            break;
        }
    }
}

/*

4
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0


5
0 3 8 999 -4
999 0 999 1 7
999 4 0 999 999
2 999 -5 0 999
999 999 999 6 0


4
0 999 4 7
2 0 999 999
999 -3 0 999
999 999 6 0

*/




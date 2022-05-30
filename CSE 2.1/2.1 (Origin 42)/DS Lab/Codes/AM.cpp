#include <stdio.h>
int graph[200][200];

int main()
{
    int n,e;
    printf("Enter no of Node: \n");
    scanf("%d",&n);

    printf("Enter no of Edge: \n");
    scanf("%d", &e);

    int so, des, we;
    for(int i=1;i<=e;i++)
    {
        scanf("%d %d %d",&so, &des, &we);
        graph[so][des]=we;
        graph[des][so]=we;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
    5
    6
    1 2 2
    1 3 3
    2 3 15
    2 4 2
    3 5 13
    4 5 9
*/

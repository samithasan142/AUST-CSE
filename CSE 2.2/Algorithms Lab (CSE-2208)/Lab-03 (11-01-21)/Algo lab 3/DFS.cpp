#include<stdio.h>
int graph[20][20], visited[20], node, edge, i, j;

void dfs(int v)
{
    int j;
    visited[v] = 1;
    printf(" %d->",v);
    for(j=1; j <= node; j++)
    {
        if(graph[v][j] && !visited[j])
            dfs(j);
    }
}

int main()
{
    printf("Enter no of Node: ");
    scanf("%d",&node);

    printf("Enter no of Edge: ");
    scanf("%d", &edge);

    int so, des;
    for(int i=1; i<=edge; i++)
    {
        scanf("%d %d",&so, &des);
        graph[so][des] = 1;
        graph[des][so] = 1;
        //for undirected graph
    }

    int v;
    printf("\nEnter the starting node: ");
    scanf("%d", &v);
    printf("DFS traversal: ");
    dfs(v);
    return 0;
}

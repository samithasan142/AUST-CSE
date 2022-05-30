#include<bits/stdc++.h>
using namespace std;

int graph[20][20], que[20], visited[20], node, edge, i, j, frnt = 0, rear = -1;

void bfs(int v)
{
    for(i = 1; i <= node; i++) //for all node
    {
        if(graph[v][i] && !visited[i]) //if there is any adjunct node and the node is not visited
        {
            que[++rear] = i; //push in the queue
        }
    }
    if(frnt <= rear)
    {
        if(visited[que[frnt]] != 1)
        {
            visited[que[frnt]] = 1;
            printf(" %d ", que[frnt]);
        }
        bfs(que[frnt++]);
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
    }

    int v;
    printf("\nEnter the starting node: ");
    scanf("%d", &v);
    visited[v] = 1;
    printf("Level order traversal: %d ", v);
    bfs(v);
    return 0;
}


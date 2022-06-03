#include<bits/stdc++.h>
#include<stack>
#define NODE 7
#define INF 9999

using namespace std;

int cost[NODE][NODE] =
{
    {INF, 3, 6, INF, INF, INF, INF},
    {INF, INF, 4, 11, 4, INF, INF},
    {INF, INF, INF, INF, 8, 11, INF},
    {INF, INF, INF, INF, INF, INF, 9},
    {INF, INF, INF, -4, INF, 2, 5},
    {INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, 2, INF}
};

void topoSort(int u, bool visited[], stack<int>&stk)
{
    visited[u] = true;
    for(int v = 0; v<NODE; v++)
    {
        if(cost[u][v])
        {
            if(!visited[v])
                topoSort(v, visited, stk);
        }
    }

    stk.push(u);
}

void shortestPath(int start)
{
    stack<int> stk;
    int dist[NODE];

    bool vis[NODE];
    for(int i = 0; i<NODE; i++){
        vis[i] = false;
    }

    for(int i = 0; i<NODE; i++){
        if(!vis[i])
            topoSort(i, vis, stk);
    }

    for(int i = 0; i<NODE; i++)
        dist[i] = INF;
    dist[start] = 0;

    while(!stk.empty())
    {
        int nextVert = stk.top();
        stk.pop();

        if(dist[nextVert] != INF)
        {
            for(int v = 0; v<NODE; v++)
            {
                if(cost[nextVert][v] && cost[nextVert][v] != INF)
                {
                    if(dist[v] > dist[nextVert] +cost[nextVert][v])
                        dist[v] = dist[nextVert] + cost[nextVert][v];
                }
            }
        }

    }
     for(int i = 0; i<NODE; i++)
            (dist[i] == INF)?cout << "Infinity ":cout << dist[i]<<" ";
}

int main()
{
    int start;
    printf("Enter Starting Node: ");
    scanf("%d", &start);
    cout << "Shortest Path From Source: "<<start<<endl;
    shortestPath(start);
}



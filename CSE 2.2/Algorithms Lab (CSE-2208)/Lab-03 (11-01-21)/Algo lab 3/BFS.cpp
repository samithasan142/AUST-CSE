#include<bits/stdc++.h>
using namespace std;
#define MX 150
vector<int>graph[MX];
bool visit[MX];
int dist[MX];

void bfs(int source)
{
    queue<int>Q;
    visit[source]=1;
    dist[source]=0;
    Q.push(source);


    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();
        for(int i=0; i<graph[node].size(); i++)
        {
            int next=graph[node][i];
            if(visit[next]==0)
            {
                visit[next]=1;
                dist[next]=dist[node]+1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int nodes,edges;
    printf("Number of Nodes: ");
    cin>>nodes;
    printf("Number of Edges: ");
    cin>>edges;
    for(int i=1; i<=edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source;

    printf("Enter the source node: ");
    cin>>source;
    bfs(source);

    cout<<"Shortest distance from node "<<source<<endl;

    for(int i=1; i<=nodes; i++)
    {
        cout<<"shortest distance of " << i << " is : " << dist[i] << endl;
    }

    return 0;
}

/*Prims Algorithm*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int v,cost;
    node(){}
    node(int vv,int cc)
    {
        v=vv;
        cost=cc;
    }
};

bool operator<(node a, node b)
{
    return a.cost>b.cost;
}

int adj_matrix[100][100];
int vertex,edge,u,v,weight,i,j,ans=0;
bool visited[100]={false};

void primsMST()
{
    priority_queue<node>pq;
    pq.push(node(1,0));
    while(!pq.empty())
    {
        node tmp=pq.top();
        pq.pop();
        if(visited[tmp.v]==1) continue;
        ans+=tmp.cost;
        visited[tmp.v]=1;

        for(i=1;i<=vertex;i++)
        {
            if(visited[i]==1) continue;
            if(adj_matrix[tmp.v][i]!=0)
                pq.push(node(i,adj_matrix[tmp.v][i]));
        }
    }
    cout<<"Minimum cost = "<<ans<<endl;
}

int main()
{
    printf("Enter number of nodes: ");
    cin>>vertex;
    printf("Enter number of edges: ");
    cin>>edge;
    printf("Enter source node, destination node & weight for %d edges: \n",edge);
    for(i=1;i<=edge;i++)
    {
        cin>>u>>v>>weight;
        adj_matrix[u][v]=weight;
        adj_matrix[v][u]=weight;
    }
    primsMST();
    return 0;
}

/*

7 9

1 6 10
3 4 12
2 7 14
3 2 16
7 4 18
4 5 22
5 7 24
5 6 25
1 2 28
*/

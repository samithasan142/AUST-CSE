#include<bits/stdc++.h>
using namespace std;

#define MX 110
int ti = 0;

vector < int > graph[MX];
bool vis[MX];
int dist[MX];
int parent[MX];


void dfs(int source){
    stack < int > Q;

    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);
    //time = time+1;
    while(!Q.empty()){
        int node = Q.top();
        Q.pop();
        //cout<< node<< " ";

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                Q.push(next);
            }
        }
        ti=ti+1;
        printf("For node %d time is %d\n", node, ti);
    }
}


int main()
{
    int nodes, edges;
    cout<<"Enter nodes and edges:";
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;
        //int x= u-65;
        //int y=v-65;
        graph[u].push_back(v);
    }

    int source;
    cin >> source;
    dfs(source);
    cout<<endl;

    return 0;
}




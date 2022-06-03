#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector < int > graph[MX];
bool vis[MX];
int dist[MX];
int parent[MX];

void bfs(int source){
    stack < int > Q;

    //initialization
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.top();
        Q.pop();
        //cout<< node<< " ";
        cout<< (node+1)*10<< " ";

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                vis[next] = 1; //visit
                dist[next] = dist[node] + 1; //update distance
                Q.push(next); // push to queue,
                //Pushing the node inside queue
                //to traverse its children
            }
        }
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
        u= (u/10)-1;
        v= (v/10)-1;
        graph[u].push_back(v); // adds an edge to the graph
    }

    int source;
    cin >> source;
    source = (source/10)-1;
    bfs(source);
    cout<<endl;

    return 0;
}

/*
    input:
    7 9
    1 2
    1 3
    1 7
    2 3
    3 7
    2 4
    4 5
    3 6
    5 6
    1
*/



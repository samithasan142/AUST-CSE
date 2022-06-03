#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector < int > graph[MX];
bool vis[MX];
int dist[MX];
int parent[MX];

void bfs(int source){
    queue < int > Q;

    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                Q.push(next);


                parent[next] = node;
            }
        }
    }
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



void printPathRecursive(int source, int node){
    if (node == source){
        cout << node << " "; // print from source
        return;
    }
    printPathRecursive(source, parent[node]);
    cout << node << " ";
}



int main()
{
    int nodes, edges;
    cout<<"Enter nodes and edges:";
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source;
    cin >> source;

    bfs(source);

    cout << "From node " << source << endl;
    for (int i = 1; i <= nodes; i++){
        cout << "Distance of " << i << " is : " << dist[i] << endl;
    }
    cout << endl;

    // path printing example

    // recursive version
    for (int i = 1; i <= nodes; i++){
        cout << "Path from " << i << " to source: ";
        printPathRecursive(source, i);
        cout << endl;
    }

    cout << endl;



    return 0;
}

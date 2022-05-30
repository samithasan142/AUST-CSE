#include<bits/stdc++.h>
using namespace std;

#define MAX 105
#define INF 1000000000

struct node{
    int value;
    int cost;
};

vector < node > G[MAX];
bool vis[MAX];
int dist[MAX];

void reset(){
    for(int i=0; i < MAX; i++){
        G[i].clear();
        vis[i] = 0;
        dist[i] = INF;
    }
}

class compare{
public:
    bool operator() (node &A, node &B){
        if(A.cost > B.cost) return true;
        return false;
    }
};

void dijkstra(int source){
    priority_queue< node, vector<node>, compare > PQ;
    PQ.push({source, 0});

    while(!PQ.empty()){
        node current = PQ.top();
        PQ.pop();

        int value = current.value;
        int cost = current.cost;

        if(vis[value] == 1) continue; // if visited, then we do not work with that node

        dist[value] = cost; // cost is finalized here
        vis[value] = 1;

        for(int i = 0; i < G[value].size(); i++){
            int nxt = G[value][i].value;
            int nxtCost = G[value][i].cost;

            if(vis[nxt] == 0){
                PQ.push({nxt, cost + nxtCost});
            }
        }
    }
}

int main()
{
    reset();

    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    // u v w
    for(int i = 1; i <=edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    cout << "Enter Source: ";
    int source;
    cin >> source;

    dijkstra(source);
    for(int i = 1; i <= nodes; i++){
        cout << "Node: " << i << " Distance: ";
        if(dist[i] == INF)
            cout << "Inf" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}

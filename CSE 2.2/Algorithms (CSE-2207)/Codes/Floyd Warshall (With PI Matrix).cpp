#include <bits/stdc++.h>
using namespace std;
#define N 5
#define I INT_MAX

void pm(int mat[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]!=I)
            cout<<mat[i][j]<<"  ";
            else
                cout<<"I"<<"  ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void printPath(int path[][N], int v, int u)
{
    if (path[v][u] == v) {
        return;
    }

    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}

void printSolution(int path[N][N])
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << v << " to " << u << " is ("
                    << v << " ";
                printPath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}

void floydWarshall(int adjMatrix[][N])
{
    int cost[N][N], path[N][N];
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u) {
                path[v][u] = -1;
            } else if (cost[v][u] != INT_MAX) {
                path[v][u] = v;
            } else {
                path[v][u] = -1;
            }
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            if (cost[v][v] < 0)
            {
                return;
            }
        }
        pm(cost);
        pm(path);
        cout<<"---------------------"<<'\n';
    }

    printSolution(path);
}

int main()
{
    int adjMatrix[N][N] =
    {
        { 0, 3, 8, I, -4 },
        { I, 0, I, 1, 7 },
        { I, 4, 0, I, I },
        { 2, I, -5, 0, I},
        { I, I, I, 6, 0}
    };
    printf("\n***Need to replace -1 with NIL & Add 1 with all other elements*** \n\n");
    floydWarshall(adjMatrix);

    return 0;
}


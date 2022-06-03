/*Kruskals Algorithm*/
#include <bits/stdc++.h>
using namespace std;

int V,E;
int parent[100];
int cost [100][100];
int findParent(int i)
{
	while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j)
{
	int a = findParent(i);
	int b = findParent(j);
	parent[a] = b;
}

void kruskalMST()
{
	int mincost = 0;
	int edge_count = 0;
    while (edge_count < V - 1)
    {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++)
            {
				if (findParent(i) != findParent(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
        cout<<"Edge "<<edge_count++<<":("<<a<<","<<b<<") Cost:"<<min<<endl;
		mincost += min;
	}
	cout<<endl<<"Minimum cost = "<<mincost;
}

int main()
{
    printf("Enter number of nodes: ");
    cin>>V;
    printf("Enter number of edges: ");
    cin>>E;

    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            cost[i][j]= INT_MAX;
        }
    }
    printf("Enter source node, destination node & weight for %d edges: \n",E);
    for(int j=1; j<=E; j++)
    {
        int source,dest;
        cin>>source>>dest;
        cin>>cost[source][dest];
    }
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

	kruskalMST();
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

/*
    Author :: Alam Khan
    Aust CSE 40th Batch
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define infinity INT_MAX
int n,m;
struct data
{
    int node;
    int cost;
    data()
    {
        ;
    }
    data(int _nod,int cos)
    {
        node = _nod;
        cost = cos;
    }
};

bool operator<(data a,data  b)
{
    return a.cost>b.cost;
}
priority_queue<data > pq;
vector<data> v[N];

int cost[N];
int vis[N];
int prim(int ver)
{
    for(int i=1;i<=n;i++)
    {
        vis[i] = 0;
        cost[i] = infinity;
    }
    cost[ver] = 0;
    pq.push(data(ver,0));
    int ans = 0;
    while(!pq.empty())
    {
        data temp = pq.top();
        pq.pop();
        if(vis[temp.node]==0)
        {
            vis[temp.node] = 1;
            ans+= temp.cost;
            for (int i=0;i<v[temp.node].size();i++)
            {
                data pa = v[temp.node][i];
                if(vis[pa.node]==0 && pa.cost<cost[pa.node])
                {
                    cost[pa.node] = pa.cost;
                    pq.push(data(pa.node,pa.cost));
                }
            }
        }

    }
    return ans;
}

int main()
{
    int t,i,j,k,x=0,y,p,q,r,ans;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>p>>q>>r;
        v[p].push_back(data(q,r));
        v[q].push_back(data(p,r));
    }
    ans = prim(1);
    cout<<ans<<endl;
    return 0;
}

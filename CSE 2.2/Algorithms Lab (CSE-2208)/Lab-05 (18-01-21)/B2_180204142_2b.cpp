#include<bits/stdc++.h>
using namespace std;

int main()
{
    int heap[]= {19,7,12,3,5,17,10,1,2};
    int n = sizeof(heap) / sizeof(heap[0]);

    priority_queue<int>que;
    for(int i=0; i<n; i++)
    {
        que.push(heap[i]);
    }
    cout<<"Heap Sort (Max heap):\n";

    while(!que.empty())
    {
        int root;
        root=que.top();
        cout<<root <<" ";
        que.pop();
    }

    return 0;
}

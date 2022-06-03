#include<bits/stdc++.h>
using namespace std;



int main()
{
    int arr[]= {2,3,6,5,1,11,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    priority_queue<int>pq1;
    for(int i=0; i<n; i++)
    {
        pq1.push(arr[i]);
    }
    cout<<"Max-heap(descending order):\n";
    while(!pq1.empty())
    {
        int root=pq1.top();
        //pq1.pop();
        cout<<root <<" ,";
        pq1.pop();
    }


    priority_queue<int,vector<int>,greater<int> >pq2;
    for(int i=0; i<n; i++)
    {
        pq2.push(arr[i]);
    }
    cout<<"\n\nMin-heap(ascending order):\n";
    while(!pq2.empty())
    {
        int root=pq2.top();
        pq2.pop();
        cout<<root<<" ,";
    }


    return 0;
}

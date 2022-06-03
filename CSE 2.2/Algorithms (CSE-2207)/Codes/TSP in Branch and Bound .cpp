#include<bits/stdc++.h>
using namespace std;
#define v 4
int minimum_cost;
string path={};

void p(int graph[][v])
{
    for (int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout<<graph[i][j]<<"  ";
        cout<<'\n';
    }

}

int reduced_matrix(int graph[v][v])
{
    int min_row = 0;
    int min_col = 0;
    for(int i=0; i<v; i++)
    {
        int minimum = 999;
        for(int j = 0; j<v; j++)
            if(graph[i][j] < minimum) minimum = graph[i][j];
        for(int j=0; j<v; j++)
            if(graph[i][j]!=999) graph[i][j]-=minimum;
        if(minimum==999) minimum=0;
        min_row+=minimum;
    }
    cout<<"\n--\n";
    p(graph);
    cout<<"\n--\n";

    for(int i=0; i<v; i++)
    {
        int minimum = 999;
        for(int j = 0; j<v; j++)
            if(graph[j][i] < minimum) minimum = graph[j][i];
        for(int j=0; j<v; j++)
            if(graph[j][i]!=999) graph[j][i]-=minimum;
        if(minimum==999) minimum=0;
        min_col+=minimum;
    }
cout<<"\n--row= "<<min_row<<" col= "<<min_col<<"\n\n";
    return (min_row+min_col);
}

void tsp(int graph[v][v],int start)
{
    minimum_cost=reduced_matrix(graph);
    vector<int> visited;
    visited.push_back(start);
    p(graph);
    cout<<minimum_cost<<'\n';
    cout<<"------------------------------"<<'\n';

    int temp[v][v],temp3[v][v],temp2[v][v],prev_cost=999,min_node,start2=start;
    memcpy(temp3, graph, sizeof(temp3));
    for(int k=1; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            if(find(visited.begin(),visited.end(),i)!=visited.end()) continue;
            memcpy(temp, temp3, sizeof(temp));
            for(int j=0; j<v; j++)
                temp[start2][j]=999;
            for(int j=0; j<v; j++)
                temp[j][i]=999;
            temp[i][start]=999;
            temp[i][start2]=999;

            int total_cost = temp3[start2][i]+minimum_cost+reduced_matrix(temp);
            p(temp);
            cout<<total_cost<<endl;
            cout<<"---------------"<<endl;
            if(total_cost<prev_cost)
            {
                prev_cost = total_cost;
                min_node=i;
                memcpy(temp2, temp, sizeof(temp2));
            }

        }
        minimum_cost=prev_cost;
        prev_cost=999;
        visited.push_back(min_node);
        start2 = min_node;
        path+=(min_node+48);
        path+="->";
        memcpy(temp3, temp2, sizeof(temp3));
        cout<<">>>>>>>>>>>>>>>>>>> "<<min_node<<" <<<<<<<<<<<<<<<<<<< "<<'\n';
    }
}



int main()
{

    int graph[v][v] = { { 999,6,10,12 },
        { 2,999,5,6 },
        { 3,9,999,8 },
        { 4,4,5,999 }
    };

    int s = 0;
    path += s+48;
    path += "->";

    tsp(graph,s);

    path+= s+48;
    cout<<"\nThe Final Path : "<<path<<endl;
    return 0;
}





#include<bits/stdc++.h>
using namespace std;


int allocation[100][100];
int maxNeed[100][100];
int needRemain[100][100];
int available[100];
int finish[100];
vector<int>taskOrder;
int process,resource;

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> process ;
    cin >> resource;

    for(int i=0; i<process; i++)
    {
        for(int j=0; j<resource; j++)
        {
            cin >> maxNeed[i][j];
        }

        for(int j=0; j<resource; j++)
        {
            cin >> allocation[i][j];
            available[j] -= allocation[i][j];
            needRemain[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    for(int i=0; i<resource; i++)
    {
        int r;
        cin >> r ;
        available[i]+=r;
    }

    while(taskOrder.size()<process)
    {
        int deadlock = 1;
        for(int i=0; i<process; i++)
        {
            if(!finish[i])
            {
                bool done = true;
                for(int j=0; j<resource; j++)
                {
                    if(needRemain[i][j]>available[j])
                    {
                        done = false;
                        break;
                    }
                }

                if(done)
                {
                    deadlock = 0;
                    finish[i] = 1;
                    taskOrder.push_back(i);
                    for(int j=0; j<resource; j++)
                    {
                        available[j]+=allocation[i][j];
                    }
                }
            }
        }

        if(deadlock)
        {
            break;
        }
    }

    if(taskOrder.size()==process)
    {
        cout << "System is in safe state and Safe Sequence is : " << endl;
        for(int i=0;i<process;i++)
        {
            cout << "P" << taskOrder[i]+1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "\nThe following system is not safe" << endl;
    }

    return 0;
}


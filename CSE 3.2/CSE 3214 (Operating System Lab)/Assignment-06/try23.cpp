#include<bits/stdc++.h>
using namespace std;
void firstfit();
void bestfit();

vector<int> block;
vector<int> block2;
vector<int> request;
vector<int> request2;


int finish[100];
int external_frag = 0;
int request_completed = 0;

int main()
{
    int x;

    cout << "Memory Block : ";
    while(cin >> x)
    {
        block.push_back(x);
        block2.push_back(x);
    }

    //cin.clear();
    cout << endl;

    cout << "Memory Request : ";
    while(cin>> x)
    {
        request.push_back(x);
        request2.push_back(x);
    }

    firstfit(vector<int> block2,vector<int> request2);
    cout<< "--------First Fit End----------"<<endl;
    bestfit(vector<int> block2,vector<int> request2);
    cout<< "--------Best Fit End----------"<<endl;

    return 0;
}

void firstfit()
{
    cout<< "--------First Fit Start----------";
    int numberOfBlock = block.size();
    int numberOfRequest  = request.size();
    finish[numberOfRequest] = {0};
    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block[j-1]>=request[i])
            {
                finish[i] = j;
                block[j-1] -= request[i];
                found = true;
                request_completed++;
                break;
            }
        }

        if(!found)
            break;
    }

    cout << endl;

    cout << "Request no" << setw(15) << "Request Size" << setw(15) << "Block no" << endl;
    for(int i=0; i<numberOfRequest; i++)
    {
        if(finish[i]!=0)
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(15) << finish[i] << endl;
        }
        else
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(25) << "No memory allocated" << endl;
        }
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        for(int i=0; i<numberOfBlock; i++)
        {
            external_frag += block[i];
        }

        cout << "External Fragmentation : " << external_frag << endl;
    }

   // block.clear();
    //*request.clear();
}

void bestfit()
{
    cout<< "--------Best Fit Start----------";
    //block.clear();
    //request.clear();
    int external_frag = 0;
    int request_completed = 0;
    int numberOfBlock = block.size();
    int numberOfRequest  = request.size();
    finish[numberOfRequest] = {0};
    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        external_frag = 0;
        int best_allocation = INT_MAX;
        int best_index = -1;

        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block[j-1]>=request[i])
            {
                found = true;
                if(best_allocation>block[j-1])
                {
                    best_allocation = block[j-1];
                    best_index = j;
                    finish[i] = best_index;
                }
            }
            external_frag += block[j-1];
        }

        if(!found)
            break;
        else
        {
            request_completed++;
            block[best_index-1] -= request[i];
            external_frag -= request[i];
        }

    }

    cout << endl;

    cout << "Request no" << setw(15) << "Request Size" << setw(15) << "Block no" << endl;
    for(int i=0;i<numberOfRequest;i++)
    {
        if(finish[i]!=0)
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(15) << finish[i] << endl;
        }
        else
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(25) << "No memory allocated" << endl;
        }
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        cout << "External Fragmentation : " << external_frag << endl;
    }
}

/*
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/

#include<bits/stdc++.h>
using namespace std;
void firstfit();

vector<int> block;
vector<int> request;

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
    }

    cin.clear();
    cout << endl;

    cout << "Memory Request : ";
    while(cin>> x)
    {
        request.push_back(x);
    }

    firstfit();

    return 0;
}

void firstfit()
{
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
}


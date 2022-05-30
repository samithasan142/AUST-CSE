#include<bits/stdc++.h>
using namespace std;

void TOH(int a, char from, char aux, char to){
    if(a==1){
        cout<<"\tMove disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    else{
        TOH(a-1, from, to, aux);
        cout<<"\tMove disk "<<a<<" from "<<from<<" to "<<to<<endl;
        TOH(a-1, aux, from, to);
    }
}

int main()
{
    int a;

    cout<<"Enter number of disks: ";
    cin>>a;
    cout<<endl;
    TOH(a, 'A', 'B', 'C');

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int set[] = {10, 20, 30, 5, 80, 100, 18, 15};
int elementsNum = 8, sum, count=0;

struct sumOfSubSet
{
    stack<int> solutionSet;
    bool solution;

    void solve(int s, int idx)
    {

        if(s>sum)
            return;

        if(s==sum){
            solution = true;

        printSolutionSet();
        return;
    }


    for(int i=idx; i<elementsNum/2; i++){
        solutionSet.push(set[i]);
        solve(s+set[i],i+1);
        solutionSet.pop();
    }
  }

  void printSolutionSet(){
        stack<int> temp;

        while (!solutionSet.empty())
        {
            cout <<  solutionSet.top() << " ";
            temp.push(solutionSet.top());
            solutionSet.pop();
            count++;
        }

    }
};

int main()
{
    sumOfSubSet ss;
    cout<<"Enter desired sum: ";
    cin>>sum;

    ss.solve(0,0);

	if(ss.solution == false)
    {
        ss.solve(0,elementsNum/2);
    }

    return 0;
}

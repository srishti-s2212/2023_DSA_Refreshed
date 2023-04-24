#include <iostream>
#include <vector>

using namespace std;

class Graphs
{
    public:
    int findJudge(vector<vector<int>> trust, int n)
    {
        //n is the number of people. n is not size of elements
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        for(vector<int> t: trust)
        {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }

        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==n-1 && outdegree[i]==0)
                return i;
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> inp = {{1,2}};
    Graphs obj;
    cout<<obj.findJudge(inp, 2);
}
#include <iostream>
#include <vector>

using namespace std;

class Graphs
{
    public:
    bool detectCycleDirected(vector<int> adj[], int v)
    {
        vector<bool> visited(v, false);
        vector<bool> dfsvisited(v, false);
        for(int i=0; i<v; i++)
        {
            if(visited[i]==false)
            {
                if(DFS(adj, visited, i, dfsvisited)==true)
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<int> adj[], vector<bool> &visited, int node, vector<bool> &dfsvisited)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                if(DFS(adj, visited, it, dfsvisited)==true)
                    return true;
            }
            else if(dfsvisited[it]==true)
                return true;
        }
        dfsvisited[node]=false;
        return false;
    }
};
int main()
{
    int v1=5;
    vector<int> adj1[5] =  {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;
    int v2=4;
    vector<int> adj2[4] = {{}, {2}, {1, 3}, {2}};
    Graphs graph;
    cout<<graph.detectCycleDirected(adj1, v1)<<endl;
    cout<<graph.detectCycleDirected(adj2, v2);
}
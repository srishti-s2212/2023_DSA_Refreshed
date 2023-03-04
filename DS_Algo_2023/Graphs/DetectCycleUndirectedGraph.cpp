#include <iostream>
#include <vector>

using namespace std;

class Graphs
{
    public:
    bool detectCycle(int v, vector<int> adj[])
    {
        
        vector<bool> visited(v, false);
        for(int i=0; i<v; i++)
        {
            if(visited[i]==false)
            {
                if(DFS(adj, visited, i, -1)==true)
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<int> adj[], vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;
            for(auto it: adj[node])
            {
                if(visited[it]==false)
                {
                    if(DFS(adj, visited, it, node)==true)
                        return true;
                }
                else if(it != parent)
                    return true;
            }
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
    cout<<graph.detectCycle(v1, adj1)<<endl;
    cout<<graph.detectCycle(v2, adj2);
}
#include <iostream>
#include <vector>

using namespace std;

class Graphs
{
    public:
    bool ifPathExists(vector<vector<int>> &edges, int s, int d)
    {
        const int n = edges.size();
        vector<int> adj[3];

        for(int i=0; i<n; i++)
        {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        return DFS(adj, s, d, visited);
    }
    bool DFS(vector<int> adj[], int s, int d, vector<bool> visited)
    {
        visited[s] = 1;
        if(s == d)
            return true;
        
        for(auto it: adj[s])
        {
            if(visited[it]==false)
            {
                if (DFS(adj, it, d, visited) == true)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0, destination = 2;
    Graphs obj;
    cout<<"Does path exist: "<<obj.ifPathExists(edges, source, destination);
}
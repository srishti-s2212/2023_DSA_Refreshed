#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graphs
{

    public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void updateMinDistTaxi(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
    
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++){
                if(grid[i][j] == 1){
                    result[i][j] = 0;
                    q.push({i, j});
                }
                    
                else{
                    //result[i][j] = BFS(grid, result, i, j, n, m);
                    
                }       
            }
        }
        BFS(grid, result, q, n, m);
        printResult(result, n, m);
    }

    //int BFS(vector<vector<int>>& grid, vector<vector<int>>& result, int i, int j, int n, int m ){
    void BFS(vector<vector<int>>& grid, vector<vector<int>>& result, queue<pair<int, int>>& q, int n, int m ){
        //vector<vector<int>> visited(n, vector<int>(m, 0));

        while(!q.empty()){
            int curr_x = q.front().first; //0
            int curr_y = q.front().second; //1
            q.pop();            
            for(int i=0; i<4; i++)
            {
                int newX= dx[i] + curr_x; //-1
                int newY= dy[i] + curr_y; //0
                if(isSafe(newX, newY, grid, n, m))
                {
                    // if(grid[newX][newY] == 0)
                    //     currDis++;
                    // if(grid[newX][newY] == 1){
                    //     currDis++;
                    //     minDist = min(minDist, currDis+1);
                    //     q.push({newX, newY});
                    // }             
                    if(result[curr_x][curr_y] + 1 < result[newX][newY]){
                        result[newX][newY] = result[curr_x][curr_y] + 1;
                        q.push({newX, newY});
                    }
                }  
            }
        }
    }

    bool isSafe(int x, int y, vector<vector<int>>& grid, int n, int m)
    {
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        return true;
    }
    void printResult(vector<vector<int>>& result, int n, int m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

//Input
// 1 0 0 0 1
// 0 0 0 0 0
// 0 0 1 0 0
// 1 0 0 0 0
// 0 0 0 0 1

//Output:
// 0 1 2 1 0
// 1 2 1 2 1
// 1 1 0 1 2
// 0 1 1 2 1
// 1 2 2 1 0

int main(){
    vector<vector<int>> grid = {{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, { 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}};
    Graphs obj;
    obj.updateMinDistTaxi(grid);

    //Update coordinates of taxis in list of pairs
}


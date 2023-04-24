#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

class Maze{
    private:
    Maze(){
        Maze top;
        Maze bottom;
        Maze right;
        Maze left;
    }
    public:
    void mazeGenerator(int n, int m){
        stack<pair<int, int>> st;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        //Another way to fill 2D vector with 0
        vector<vector<int>> visited2;
        fill(visited2.begin(), visited2.end(), 0);

        // //General syntax of memset
        // void* memset( void* obj, int val, size_t num);
        // //Memset works on arrays, not vectors
        // bool visited3[5][5];
        // memset(visited3, 0, sizeof(visited3));

        int visitedCount = 0;

        st.push({0, 0});
        visitedCount = 1;

        while(visitedCount < n*m){
            
            pair<int, int> currCell = st.top();
            //Find valid neighbours of st.top()
            pair<int, int> nextCell = getNeighbours(st.top(), st, visited);

            if(nextCell.first && nextCell.second) {
                st.push(nextCell);
                visited[nextCell.first][nextCell.second] = true;
                removeWall(currCell, nextCell);
                currCell = nextCell;
                visitedCount++;
            }
            else{
                st.pop();
            }       
        }

    }

    pair<int, int> getNeighbours(pair<int, int> node, stack<pair<int, int>> st,  vector<vector<int>> visited){
        int x = st.top().first;
        int y = st.top().second;

        vector<pair<int, int>> neighbours;

        //Top
        if (x-1 > 0 && visited[x-1][y] == 0){
            neighbours.push_back({x-1, y});
        }
        //Bottom
        if (x+1 > 0 && visited[x+1][y] == 0){
            neighbours.push_back({x-1, y});
        }

        //Left
        if (y-1 > 0 && visited[x][y-1] == 0){
            neighbours.push_back({x-1, y});
        }

        //Right
        if (y+1 > 0 && visited[x][y+1] == 0){
            neighbours.push_back({x-1, y});
        }

        pair<int, int> nextCell;
        if(neighbours.size()>0){
            nextCell = neighbours[rand() % neighbours.size()];
        }
        else return {NULL, NULL};

        return nextCell;
    }

    void removeWall(pair<int, int> currCell, pair<int, int> nextCell){

        int curr_x = currCell.first;
        int curr_y = currCell.second;

        int next_x = nextCell.first;
        int next_y = nextCell.second;

        // //Top
        // if((curr_y == curr_y) && (curr_x == next_x+1)){
        //     Maze.top = Maze.botttom=false;
        // }
        // if(curr.col==nxt.col && curr.row == nxt.row-1){///bottom
        //     curr.botttom = nxt.top = false;
        // }
        // if(curr.col==nxt.col-1 && curr.row==nxt.row ){///right
        //     curr.right = nxt.left = false;
        // }
        // if(curr.col == nxt.col+1 && curr.row == nxt.row){///left
        //     curr.left = nxt.right = false;
    }
};
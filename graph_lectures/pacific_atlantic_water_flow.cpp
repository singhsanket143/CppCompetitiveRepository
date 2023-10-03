#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    
    vector<vector<int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // i, j -> i+1, j -> i-1, j -> i, j-1 -> i, j+1
    int rows;
    int cols;
    vector<vector<int> > h;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;
        queue<pair<int, int> > pacificbfs;
        queue<pair<int, int> > atlanticbfs;
        
        // steo of multisource bfs
        for(int i = 0; i < rows; i++) {
            pacificbfs.push({i, 0});
            atlanticbfs.push({i, cols-1});
        }
        
        for(int j = 1; j < cols; j++) {
            pacificbfs.push({0, j});
        }
        
        for(int j = 0; j < cols-1; j++) {
            atlanticbfs.push({rows-1, j});
        }
        
        vector<vector<bool> > pacific = bfs(pacificbfs);
        vector<vector<bool> > atlantic = bfs(atlanticbfs);
        
        vector<vector<int> > result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] and atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
    
    vector<vector<bool> > bfs(queue<pair<int, int> > &qu) {
        vector<vector<bool> > visited(rows, vector<bool> (cols, false));
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for(int d = 0; d < 4; d++) {
                int newRow = i+dir[d][0];
                int newCol = j+dir[d][1];
                if(newRow < 0 or newCol < 0 or newRow >= rows or newCol >= cols) continue; // you exited the grid
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol] < h[i][j]) continue; // h[newRow][newCol] -> neighbours height, h[i][j] -> curr cell's heigh
                qu.push({newRow, newCol});
            }
        }
        return visited;
    }
};
int main() {

    return 0;
}
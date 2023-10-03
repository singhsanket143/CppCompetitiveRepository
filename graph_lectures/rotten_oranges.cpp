#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > qu;
        int fo = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) qu.push({i, j}); /// multi source bfs step
            }
        }
        // we have added all the src
        qu.push({-1, -1});
        int mins = 0;
        vector<vector<int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            if(cell.first == -1 and cell.second == -1) {
                mins++;
                if(not qu.empty()) {
                    qu.push({-1, -1});
                } else {
                    break;
                }
            } else {
                int i = cell.first;
                int j = cell.second;
                for(int d = 0; d < 4; d++) {
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
                    if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
                    if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    fo--;
                    grid[nr][nc] = 2;
                    qu.push({nr, nc});
                }
            }
        }
        return (fo == 0) ? mins-1 : -1;
    }
};
int main() {

    return 0;
}
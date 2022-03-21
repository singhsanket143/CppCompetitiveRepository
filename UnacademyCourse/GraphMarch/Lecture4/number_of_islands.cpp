class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void dfs(std::vector<std::vector<bool> > &vis, vector<vector<char>>& grid, int i, int j) {
        vis[i][j] = true;
        for(int d = 0; d < 4; d++) {
            if(i+dx[d] < 0 or i+dx[d] >= grid.size() or j+dy[d] < 0 or j+dy[d] >= grid[0].size()) continue;
            if(not vis[i+dx[d]][j+dy[d]] and grid[i+dx[d]][j+dy[d]] == '1') {
                
                dfs(vis, grid, i+dx[d], j+dy[d]);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cc = 0;
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<bool> > vis(n, std::vector<bool> (m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(not vis[i][j] and grid[i][j] == '1') {
                    cc++;
                    
                    dfs(vis, grid, i, j);
                }
            }
        }
        return cc;
    }
};
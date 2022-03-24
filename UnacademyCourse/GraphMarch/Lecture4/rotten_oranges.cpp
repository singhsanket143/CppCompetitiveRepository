// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         std::queue<std::pair<int, int> > qu;
//         int countFreshOranges = 0;
//         int dirX[4] = {1, -1, 0, 0};
//         int dirY[4] = {0, 0, 1, -1};
//         int m = grid.size(), n = grid[0].size();
        
//         for(int i = 0; i < m; i++) { // initiation of multi source bfs
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == 2) {
//                     qu.push({i, j});
//                 } else if(grid[i][j] == 1) {
//                     countFreshOranges++;
//                 }
//             }
//         }
        
//         qu.push({-1, -1});
//         int minutes = -1;
//         while(not qu.empty()) {
//             std::pair<int, int> curr = qu.front();
//             qu.pop();
//             int row = curr.first;
//             int col = curr.second;
//             if(row == -1 and col == -1) {
//                 minutes++;
//                 if(not qu.empty()) {
//                     qu.push({-1, -1});
//                 }
//             } else {
//                 for(int d = 0; d < 4; d++) {
//                     int neighRow = row+dirX[d];
//                     int neighCol = col+dirY[d];
//                     if(neighRow >= 0 and neighRow < m and neighCol >= 0 and neighCol < n) {
//                         if(grid[neighRow][neighCol] == 1) {
//                             grid[neighRow][neighCol] = 2;
//                             countFreshOranges--;
//                             qu.push({neighRow, neighCol});
//                         }
//                     }
//                 }
//             }
//         }
//         return countFreshOranges == 0 ? minutes : -1;
//     }
// };
#include<iostream>
#include<unordered_map>
int main(int argc, char const *argv[])
{
    std::cout<<"hello";
    std::unordered_map<int, int> mp;
    mp[1] = 0;
    return 0;
}

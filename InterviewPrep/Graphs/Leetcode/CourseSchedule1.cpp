#include <iostream>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, bool> visited;
        queue<int> qu;
        int **adjmat = new int*[numCourses];
        for(int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
            visited[i] = false;
            adjmat[i] = new int[numCourses]();
        }
        
        for(int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            if(adjmat[x][y]==0) {
                adjmat[y][x] = 1;
                indegree[x]++;
            } else {
                vector<int> empty;
                return false;
            }
        }
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> result;
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            result.push_back(node);
            for(int j = 0; j < numCourses; j++) {
                if(adjmat[node][j]==1) {
                    indegree[j]--;
                    if(indegree[j] == 0) {
                        qu.push(j);
                    }
                }
            }
        }
        
        if(result.size() == numCourses) {
            return true;
        } else {
            vector<int> empty;
            return false;
        }
    }
};
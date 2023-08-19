#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
bool cmp(vector<int> &i1, vector<int> &i2) {
    return i1[1] < i2[1] ;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= lastEndTime) {
                ans++;
            } else {
                lastEndTime = intervals[i][1];
            }
        }
        return intervals.size() - ans;
    }
};

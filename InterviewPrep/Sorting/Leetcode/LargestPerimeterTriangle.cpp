#include <iostream>
class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>()); 
        for(int i = 0; i <= arr.size() - 3; i++) {
            if((arr[i+1] + arr[i+2]) <= arr[i]) continue;
            else return arr[i]+arr[i+1]+arr[i+2];
        }
        return 0;
    }
};
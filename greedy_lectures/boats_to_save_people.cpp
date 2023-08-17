#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/boats-to-save-people/ 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /**
         * Time: O(nlogn)
         * Space:O(sort)
        */
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int bt = 0;
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                bt++; // allocate a boat to the pair
                i++;
                j--;
            } else {
                bt++; // allocate a boat to the heaviest
                j--;
            }
        }
            return bt;
    }
};
int main() {

    return 0;
}
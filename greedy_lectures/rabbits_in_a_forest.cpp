#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // Time: O(n)
        // Space: O(n)
        unordered_map<int, int> mp;
        int result = 0;
        for(int i = 0; i < answers.size(); i++) {
            if(!mp[answers[i] + 1]) {
                result += answers[i] + 1; // we started a new gcolor group
                if(answers[i] == 0) continue;
                mp[answers[i] + 1] = 1; // (1) : 1
            } else {
                mp[answers[i] + 1]++; //(1):2
                int key = answers[i] + 1;
                int val = mp[key];
                if(key == val) {
                    // we found all the rabbits of the group
                    // eliminate the grpup
                    mp.erase(key);
                }
            }
        }
        return result;
    }
};
int main() {

    return 0;
}
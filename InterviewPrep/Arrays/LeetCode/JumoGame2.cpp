#include<iostream>
#include<vector>
using namespace std;


int Jump(vector<int> &nums) {
//Write your code here
    if (nums.size() <= 1) return 0;
    int ladder = 0;
    int stair = 1;
    int jump = 0;
    for (int level = 0; level < nums.size(); level++) {
        if (level == nums.size() - 1) {
            return jump;
        }
        if (nums[level] + level >= ladder) {
            ladder = nums[level] + level;
        }
        stair--;
        if (stair == 0) {
            jump++;

            stair = ladder - level;
            if (stair == 0) {
                return -1;
            }
        }
    }
    return jump;

}


int main(int argc, char**argv) {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int res = Jump(v);
    cout << res << endl;
}
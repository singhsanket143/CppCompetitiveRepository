#include "iostream";
#include "unordered_map";
#include "vector";
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            if (abs(mp[nums[i]] - i) <= k)
                return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    return 0;
}

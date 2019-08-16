#include "iostream";
#include "unordered_map";
#include "vector";
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            return true;
        }
        mp[nums[i]] = nums[i];
    }
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

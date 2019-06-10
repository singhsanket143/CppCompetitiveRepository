#include <iostream>
#include "vector";
#include "unordered_map";
#include "algorithm";
#include "climits";
using namespace std;

int findPairs(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    if (k < 0)
        return 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) == mp.end())
        {
            mp[nums[i]] = 1;
        }
        else
        {
            mp[nums[i]]++;
        }
    }

    int count = 0;
    if (k == 0)
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second >= 2)
            {
                count++;
            }
        }
    }
    else
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (mp.find(it->first + k) != mp.end())
            {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

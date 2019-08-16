#include <iostream>
#include "vector";
#include "algorithm";
#include "climits";
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

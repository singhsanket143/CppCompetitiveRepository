#include <iostream>
#include "vector";
#include "algorithm";
#include "climits";
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int bestCount = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            bestCount = bestCount < count ? count : bestCount;
            count = 0;
            continue;
        }
        else
        {
            count++;
        }
    }
    bestCount = bestCount < count ? count : bestCount;
    return bestCount;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

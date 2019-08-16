#include <iostream>
#include "vector";
#include "algorithm";
#include "climits";
using namespace std;

int thirdMax(vector<int> &nums)
{
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] != first && nums[i] > second)
        {
            third = second;
            second = nums[i];
        }
        else if (nums[i] != second && nums[i] != first && nums[i] > third)
        {
            third = nums[i];
        }
    }

    if (third != LONG_MIN)
        return third;
    return first;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

#include <iostream>
using namespace std;

int maximumProduct1(vector<int> &nums) // O(logN) solution
{
    sort(nums.begin(), nums.end());
    int candidate1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
    if (nums[0] < 0 and nums[1] < 0)
    {
        int candidate2 = nums[nums.size() - 1] * nums[0] * nums[1];
        return candidate1 > candidate2 ? candidate1 : candidate2;
    }
    else
    {
        return candidate1;
    }
}
int maximumProduct(vector<int> &nums) // O(n) solution
{
    int firstL = nums[0], secondL = -1001, thirdL = -1001;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= firstL)
        {
            thirdL = secondL;
            secondL = firstL;
            firstL = nums[i];
        }
        else if (nums[i] >= secondL)
        {
            thirdL = secondL;
            secondL = nums[i];
        }
        else if (nums[i] > thirdL)
        {
            thirdL = nums[i];
        }
    }
    int m = 1001, n = 1001;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= m)
        {
            n = m;
            m = nums[i];
        }
        else if (nums[i] <= n)
        {
            n = nums[i];
        }
    }
    int candidate1 = firstL * secondL * thirdL;
    int candidate2 = firstL * m * n;
    return candidate1 > candidate2 ? candidate1 : candidate2;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

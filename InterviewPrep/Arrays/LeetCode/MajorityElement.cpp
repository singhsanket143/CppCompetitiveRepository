#include "iostream";
#include "vector";
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 1;
    int candidate = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (count <= 0 && i != 1)
        {
            candidate = nums[i];
        }
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main(int argc, char const *argv[])
{

    return 0;
}

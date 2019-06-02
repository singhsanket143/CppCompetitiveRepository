#include "iostream";
#include "vector";
using namespace std;

int missingNumber(vector<int> &arr)
{
    int n = arr.size();
    int x = 10;
    bool zero = false;
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) == n)
        {
            x *= -1;
        }
        else
        {
            if (arr[abs(arr[i])] == 0)
                zero = true;
            else
                arr[abs(arr[i])] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 and zero == false)
            return i;
        if (arr[i] > 0)
            return i;
    }
    if (x > 0)
        return n;
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

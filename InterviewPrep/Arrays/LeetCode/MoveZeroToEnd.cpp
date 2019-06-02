#include "iostream";
#include "vector";
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int l = 0, r = 0;
    while (r < arr.size())
    {
        if (l != r and arr[l] == 0 and arr[r] != 0)
        {
            swap(arr[l++], arr[r]);
        }
        else if (arr[l] == 0 and arr[r] == 0)
            r++;
        else
        {
            r++;
            l++;
        }
    }
    while (l < arr.size())
    {
        arr[l++] = 0;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

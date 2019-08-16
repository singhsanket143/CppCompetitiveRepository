#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

int count_ = 0;

bool checksquareful(int x, int y)
{
    double sq = sqrt(x + y);
    return (sq - floor(sq)) == 0;
}

void helper(vector<int> &arr, int start)
{
    if (start > 1 and (!checksquareful(arr[start - 2], arr[start - 1])))
    {
        return;
    }
    if (start == (arr.size() - 1) and !checksquareful(arr[start], arr[start - 1]))
    {
        return;
    }
    if (start == (arr.size() - 1))
    {
        count_++;
        return;
    }
    unordered_map<int, bool> mp;
    for (int i = start; i < arr.size(); i++)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = true;
            swap(arr[i], arr[start]);
            helper(arr, start + 1);
            swap(arr[i], arr[start]);
        }
    }
}
int numSquarefulPerms(vector<int> &arr)
{
    helper(arr, 0);
    return count_;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout << numSquarefulPerms(v) ;
    return 0;
}

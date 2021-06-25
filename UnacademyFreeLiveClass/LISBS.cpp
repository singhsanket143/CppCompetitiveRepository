#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int lis(std::vector<int> &arr) {
    // O(nlogn)
    int n = arr.size();
    std::vector<int> dp(n, 1);
    std::map<int, int> mp;
    mp[arr[0]] = 1;
    for(int i = 1; i < n; i++) {
        auto it = mp.lower_bound(arr[i]+1); // first val > arr[i]
        if(it != mp.begin()) {
            it--;
            dp[i] += it->second;
        }
        mp[arr[i]] = dp[i];
        it = mp.upper_bound(arr[i]); // first value greater than x;
        while(it != mp.end() and it->second <= dp[i]) {
            auto t = it;
            t++;
            mp.erase(it);
            it = t;
        }
    }
    return *(std::max_element(dp.begin(), dp.end()));
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) std::cin>>arr[i];
    std::cout<<lis(arr);
    return 0;
}

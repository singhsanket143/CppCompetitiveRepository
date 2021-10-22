// header files
#include<iostream>
#include<unordered_map>

int main()
{
    int t;
    std::cin>>t;
    while(t > 0) {
        int n;
        std::cin>>n;
        std::unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin>>x;
            mp[x]++;
        }
        int ans = 0;
        for(auto pp : mp) {
            int y = pp.first;
            if(mp.count(2*y)) {
                ans += mp[y]*mp[2*y];
            }
        }
        std::cout<<ans<<"\n";
        t = t - 1;
    }
    return 0;
}
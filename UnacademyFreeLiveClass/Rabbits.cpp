#include<iostream>
#include<cstring>
#include<vector>
#define ll long long int
#define vv std::vector<std::vector<ll> >
#define vi std::vector<ll>
#define inf 1e18
vi dp((1<<16), inf);
vi score((1<<16), 0);

ll calc(vv &arr, int subset) {
    ll ans = 0;
    for(int i = 0; i <= 16; i++) {
        for(int j = i+1; j <= 16; j++) {
            if(((subset&(1<<i)) != 0) and ((subset&(1<<j)) != 0)) {
                ans += arr[i][j];
            }
        }
    }
    return ans;
}
void precompute(vv &arr, int n) {
    for(int subset = 1; subset <= ((1<<n)-1); subset++) {
        score[subset] = calc(arr, subset);
    }
}


ll f(vv &arr, int mask) {
    if(mask == 0) return 0;
    if(dp[mask] != inf) {
        return dp[mask];
    }
    ll ans = 0;
    for(int submask = mask; submask != 0; submask = (submask-1)&mask) {
        ans = std::max(ans, score[submask]+f(arr, mask^submask));
    }
    return dp[mask] = ans;
}
int main(int argc, char const *argv[])
{
    
    int n;
    std::cin>>n;
    vv arr(n, vi(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin>>arr[i][j];
        }
    }
    clock_t begin = clock();
    precompute(arr, n);
    std::cout<<f(arr, (1<<n)-1);
    #ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}

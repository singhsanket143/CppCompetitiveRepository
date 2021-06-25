#include<iostream>
#include<vector>
#include<iomanip>

double dp[3005][3005];
double atleastXheads(std::vector<double> &arr, int i, int x) {
    if(x == 0) return 1;
    if(i == 0) return 0;
    if(dp[i][x] > -0.8) {
        return dp[i][x];
    }

    return dp[i][x] = arr[i]*atleastXheads(arr, i-1, x-1) + (1-arr[i])*atleastXheads(arr, i-1, x);
}

int main() {

    int n;
    std::cin>>n;
    std::vector<double> arr(n+1);
    std::memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) std::cin>>arr[i];

    std::cout<<std::fixed<<std::setprecision(9)<<atleastXheads(arr, n, (n+1)/2);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int f(int n) {
    if(n == 0 or n == 1) return n;
    // dp check, to indentify if problem was already solved earlier
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1) + f(n-2); // storing ans
} 

int main() {
    int n;
    cin>>n;
    dp.clear(); 
    dp.resize(n+1, -1); // dp[i] == -1 -> that ith subproblem is not yet computed
    cout<<f(n)<<"\n";
    return 0;
}
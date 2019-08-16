#include "iostream"
using namespace std;

int dp[1000] = {0};

int catalan(int n) {
    if(n == 0 or n == 1) {
        return 1;
    }
    if(dp[n]!=0) {
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += catalan(i-1)*catalan(n-i);
    }
    dp[n] = ans;
    return ans;
}

int main(int argc, char* argv[])
{

    for(int i=0;i<=10;i++){
        cout<<catalan(i)<<", ";
    }
    return 0;
}

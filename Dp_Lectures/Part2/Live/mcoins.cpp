#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, l, m;
    // m-> no of games
    cin>>k>>l>>m;

    vector<bool> dp(1000005, 0);

    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;

    for(int i = 2; i <= 1000000; i++) {
        if(i == k or i == l) continue;

        dp[i] = !(dp[i-1] and ((i - k >= 1) ? dp[i-k] : 1) and ((i - l >= 1)  ? dp[i-l] : 1));
    }

    for(int i = 0; i < m; i++) {
        int n;
        cin>>n;
        if(dp[n] == 1 ){
            // n-> winning state
            cout<<"A";
        } else {
            // n-> loosing state
            cout<<"B";
        }
    }

    return 0;
}
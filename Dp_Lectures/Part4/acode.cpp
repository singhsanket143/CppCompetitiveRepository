#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

// string decode(string &input) {
//     string res = "";
//     if(input.size() == 1) {
//         res += (char)(64 + input[0] - '0');
//     } else {
//         int num = (input[0] - '0')*10 + (input[1] - '0');
//         res += (char)(64 + num);
//     }
//     return res;
// }

vector<ll> dp;

ll f(string &str, int i) {
    if(i <= 0) return 1;
    if(dp[i] != -1) return dp[i];
    ll ans = 0;
    if(str[i] - '0' > 0) {
        ans+=f(str, i-1);
    } 
    if(str[i-1]-'0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26) {
        ans += f(str, i-2);
    }

    return dp[i] = ans;
}

ll fbu(string &str) {
    dp.resize(5005, 0);

    dp[0] = (str[0] != '0');
    if(str.size() > 1) {
        if(str[1] != '0') dp[1] += dp[0];
        if(str[1-1] - '0' > 0 and (str[0] - '0')*10 + (str[1] - '0') <= 26) dp[1]++;
    }
    for(int i = 2; i < str.size(); i++) {
        ll ans = 0;
        if(str[i] - '0' > 0) {
            ans+=dp[i-1];
        } 
        if(str[i-1]-'0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26) {
            ans += dp[i-2];
        }
        dp[i] = ans;
    }
    return dp[str.size() - 1];

}


int main() {

    string n;
    cin>>n;
    while(n[0] != '0') {
        dp.clear();
        cout<<fbu(n)<<"\n";
        // cout<<f(n, n.size() - 1)<<"\n";
        cin>>n;
    } 

    return 0;
}
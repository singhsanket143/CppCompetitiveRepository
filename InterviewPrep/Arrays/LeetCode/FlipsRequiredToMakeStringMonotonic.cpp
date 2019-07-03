#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a string
// It should return required output.
int minFlipsMonoIncr(string &S) {

    // Write your code here
    ll n = S.size();
    ll *freq = new ll[n + 1];
    for (int i = 0; i <= n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[i + 1] = freq[i] + (S[i] == '1' ? 1 : 0);
    }
    ll ans = INT_MAX;
    for (int j = 0; j <= n; j++) {
        ans = min(ans, freq[j] + n - j - (freq[n] - freq[j]));
    }
    return (int)ans;
}

int main(int argc, char** argv) {
    string s;
    cin >> s;
    cout << minFlipsMonoIncr(s);
}
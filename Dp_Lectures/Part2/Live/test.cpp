#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <set>
#include <map>
#include <iterator>

using namespace std;
#define ll long long
#define ull unsigned long long
vector<int>dp;
// Sort array in discending order (n to 1)

vector<int> getDigits(int n){
    vector<int> res;
    while(n>0){
        if(n%10!=0){
            res.push_back(n%10);
        }
        n/=10;
    }
    return res;
}

int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int>d = getDigits(n);
    int res = INT_MAX;
    for(int i=0;i<d.size();i++){
        res = min(res,f(n-d[i]));
    }
    return dp[n]= 1+res;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
   dp.resize(1000006,-1);
   int ans = f(n);

   cout<<ans;
   return 0;
}
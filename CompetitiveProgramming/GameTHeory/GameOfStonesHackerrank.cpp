#include<bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;
 
    while (Set.find(Mex) != Set.end())
        Mex++;
 
    return (Mex);
}

int calculateGrundy (int n, int dp[])
{
    if (n <= 1)
        return (0);
    if(dp[n] != 0) {
        return dp[n];
    }
 
    unordered_set<int> Set; 
 
    Set.insert(calculateGrundy(n-2, dp));
    Set.insert(calculateGrundy(n-3, dp));
    Set.insert(calculateGrundy(n-5, dp));
    
    dp[n] = calculateMex(Set);
    return (dp[n]);
}

int main()
{
    int t;
    cin>>t;
    int dp[10000];
    while(t--) {
        int n;
        cin>>n;
        if(calculateGrundy (n, dp)) {
            cout<<"First"<<endl;
        } else {
            cout<<"Second"<<endl;
        }
    }
    
    return (0);
}
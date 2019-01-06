#include<bits/stdc++.h> 
using namespace std; 
  
int dp[1000]; 
  
int countFriendsPairings(int n) 
{ 
    if(dp[n]!=-1) 
    return dp[n]; 
  
    if(n>2)  
    return dp[n] = countFriendsPairings(n-1)+  
                (n-1)*countFriendsPairings(n-2); 
    else
    return dp[n] = n; 
} 
  
int main() 
{ 
    memset(dp,-1,sizeof(dp)); 
int n = 4;  
    cout << countFriendsPairings(n) << endl;  
} 
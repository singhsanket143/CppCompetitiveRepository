#include <iostream>
using namespace std;
long long int dp[21][2];

long long int countWays(int last,int index, int n, int k)
 {
  if(dp[index][last]!=-1) return dp[index][last];
  if(index>=n) return 0;
  if(index==n-1)
   {
     if(last==0) dp[index][last]=k-1;
     else dp[index][last]=k;
     return dp[index][last];
   }
  
      long long int ret=0;
        for(int i=0;i<k;i++)
         {
            if(last==0 and i==0) continue;
           
             if(i==0)
             ret+=countWays(0,index+1, n, k);
             else ret+=countWays(1,index+1, n, k);
  		 }
  
    dp[index][last]=ret;
   
      return ret;

 }
int main()
 {
		int n,k;
    
        for(int i=0;i<=20;i++) {
         dp[i][0]=-1;dp[i][1]=-1;
    	}
   
        cin>>n>>k;
        long long int ans=countWays(0,0, n, k);
        cout<<ans<<endl;
  
 }
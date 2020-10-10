#include <iostream>
#define ll long long int
using namespace std;
ll dp[1000] = {0};
int ropeCut(int n) {
	if(n==0 or n==1 or n==2 or n==3 or n==4) return n;
	int result = 0;
	for(int i=1;i<n;i++) {
		result = max(result, max(i*(n-i), i*ropeCut(n-i)));
	}
	return result;
}

ll ropeCutTD(int n) {
	if(n==0 or n==1 or n==2 or n==3 or n==4) return n;
	if(dp[n]!=0) return dp[n];
	ll result = 0;
	for(int i=1;i<n;i++) {
		result = max(result, (ll)i*ropeCutTD(n-i));
	}
	dp[n]=result;
	return result;
}

ll ropeCutBU(int n) {
	int dpBU[1000]={0};
	dpBU[0] = 0;
	dpBU[1] = 1;
	dpBU[2] = 2;
	dpBU[3] = 3;
	dpBU[4] = 4;

	for(int i=5;i<=n;i++) {
		for(int j=1;j<i;j++) {
			dpBU[i] = max(dpBU[i], dpBU[j]*dpBU[i-j]);
		}
	}
	return dpBU[n];
}

int main(int argc, char const *argv[])
{
	cout<<ropeCutTD(15)<<endl;
	cout<<ropeCutBUcle(15)<<endl;
	cout<<ropeCut(15);
	return 0;
}





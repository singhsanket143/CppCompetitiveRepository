#include <iostream>
using namespace std;
int dp[1005] = {0};

int minStepsBU(int n) {
	int dp[1005] = {0};
	dp[0] = INT_MAX;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++) {
		int div_by_3 = INT_MAX;
		int div_by_2 = INT_MAX;
		int sub_by_1 = INT_MAX;
		if(i%3 == 0) {
			div_by_3 = 1+dp[i/3];
		}
		if(i%2 == 0) {
			div_by_2 = 1+dp[i/2];
		}
		sub_by_1 = 1+dp[i-1];
		dp[i] = min(sub_by_1, min(div_by_2, div_by_3));
	}

	return dp[n];
}


int minStepsTD(int n) {
	if(n==1 or n==2 or n==3) return 1;
	if(dp[n]!=0) return dp[n];
	int div_by_3 = INT_MAX;
	int div_by_2 = INT_MAX;
	int sub_by_1 = INT_MAX;
	if(n%3==0) {
		div_by_3 = 1 + minStepsTD(n/3);
	}
	if(n%2==0) {
		div_by_2 = 1 + minStepsTD(n/2);
	}
	sub_by_1 = 1 + minStepsTD(n-1);

	int result = min(sub_by_1, min(div_by_2, div_by_3));
	dp[n] = result;
	return result;
}

int minSteps(int n) {
	if(n==1 or n==2 or n==3) return 1;
	int div_by_3 = INT_MAX;
	int div_by_2 = INT_MAX;
	int sub_by_1 = INT_MAX;
	if(n%3==0) {
		div_by_3 = 1 + minSteps(n/3);
	}
	if(n%2==0) {
		div_by_2 = 1 + minSteps(n/2);
	}
	sub_by_1 = 1 + minSteps(n-1);

	return min(sub_by_1, min(div_by_2, div_by_3));
}

int main(int argc, char const *argv[])
{
	cout<<minStepsBU(1000)<<endl;
	cout<<minStepsTD(1000)<<endl;
	cout<<minSteps(1000);
	return 0;
}

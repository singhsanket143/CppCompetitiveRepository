#include <iostream>
using namespace std;



int lengthOfLIS(int *arr, int n) {
        if(n==0) {
            return 0;
        }
        int *dp = new int[n];
        for(int i=0;i<n;i++) {
            dp[i] = 1;
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(arr[j]<arr[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int result = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
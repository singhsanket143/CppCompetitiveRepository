import java.util.*;
public class Solution {

    public static int NoOfBST(int n) {
        int MOD = 1000000007;
        int dp[] = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            //long sum = 0;
            for (int k = 1; k <= i; k++) {
                long left = (long)dp[k - 1];
                long right = (long)dp[i - k];
                int ans1 = (int)(left % MOD);
                int ans2 = (int)(right % MOD);
                int ans = (ans1 * ans2) % MOD;
                long res = (long)((dp[i] % MOD) + (ans) % MOD);
                dp[i] = (int)(res % MOD);
            }
        }
        // System.out.println();
        return dp[n];
    }

    public static void main(String[] args) {

    }
}
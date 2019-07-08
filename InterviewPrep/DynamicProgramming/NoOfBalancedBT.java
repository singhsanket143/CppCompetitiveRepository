import java.util.*;

class NoOfBalancedBT {
	public static int balancedTreesOfHeightH(int height) {
		// Write your code here
		long dp[] = new long[height + 1];
		int mod = 1000000007;
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= height; i++) {
			long cand1 = dp[i - 1];
			long cand2 = dp[i - 2];
			dp[i] = ((cand1 % mod) * (cand1 % mod) + 2 * (cand1 % mod) * (cand2 % mod)) % mod;
		}


		return (int)dp[height];

	}
	
	public static void main(String[] args) {
		
	}
}
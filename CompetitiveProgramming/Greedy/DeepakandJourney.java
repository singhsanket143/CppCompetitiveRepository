import java.util.*;

public class DeepakandJourney {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();  // Take input for test cases
		while(t-- > 0) {
			int n = scn.nextInt();  // Take input of n i.e. total check points
			long[] C = new long[n+1]; // For simplicity prepare arrays of size n+1 to convert it to 1 based indexing
			long[] L = new long[n+1];
			for(int i = 1; i <= n; i++) {
				C[i] = scn.nextInt(); //Take input for array C
			}
			for(int i = 1; i <= n; i++) {
				L[i] = scn.nextInt(); //Take input for array L
			}
			long mi = Long.MAX_VALUE; // Variable to take care of the minimum cost of petrol upto a checkpoint X
			long ans = 0;
			for(int i=1;i<=n;i++) {
				mi = Math.min(mi, C[i]); // Compare the cose of petrol between cost at current checkpoint and the minimum cost till now
				ans+= (mi*L[i]);
			}
			System.out.println(ans);
		}
	}
}
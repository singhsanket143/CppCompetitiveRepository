import java.util.*;

public class Kth_Number_In_Union_Of_Segments {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		long k = scn.nextLong();
		long[] left = new long[n];
		long[] right = new long[n];
		for(int i = 0; i < n; i++) {
			left[i] = scn.nextLong();
			right[i] = scn.nextLong();
		}
		long lo = Integer.MIN_VALUE;
		long hi = Integer.MAX_VALUE;
		long result = -1;
		while(lo <= hi) {
			long mid = lo + (hi - lo) / 2;
			long count = 0;
			for(int i = 0; i < n; i++) {
				if(left[i] >= mid) continue;
				else {
					count += Math.min(mid - left[i], right[i] - left[i] + 1);
				}
			}
			if(count > k) hi = mid - 1;
			else {
				result = mid;
				lo = mid + 1;
			}
		}
		System.out.println(result);
	}
}
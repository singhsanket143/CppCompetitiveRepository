import java.util.Arrays;
import java.util.Scanner;

public class aggresiveCows {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
			int n = scn.nextInt();
			int k = scn.nextInt();
			int[] arr = new int[n];
			int max = Integer.MIN_VALUE;
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				arr[i] = scn.nextInt();
				if (arr[i] > max) {
					max = arr[i];
				}
				if (arr[i] < min) {
					min = arr[i];
				}
			}
			int helper = max;
			System.out.println(distribution(arr, k, helper));

	}

	public static int distribution(int[] arr, int cows, int helper) {
		Arrays.sort(arr);
		int lo = 1, hi = helper;
		int result = 0;
		while (lo <= hi) {
			int mid = (hi + lo) / 2;
			if (isValid(cows, mid, arr)) {
				lo = mid + 1;
				result = mid;
			} else {
				hi = mid - 1;
			}
		}
		return result;

	}

	public static boolean isValid(long cows, int ans, int[] a) {
		int count=1;
		int last_pos=a[0];
		for(int i=1;i<a.length;i++){
			if(a[i]-last_pos>=ans){
				count++;
				last_pos=a[i];
			}
			if(count==cows){
				return true;
			}
		}
		return false;
	}

}
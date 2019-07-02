import java.util.*;

class targetsubset {
	public static void main(String[] args) {
		
	}

	public static void targetSubset(int[] arr, int si, int target, String osf) {
		if (si == arr.length) {
			if (target == 0) {
				System.out.println(osf);
			}
			return;
		}
		targetSubset(arr, si + 1, target, osf);
		targetSubset(arr, si + 1, target - arr[si], osf + arr[si] + " ");
	}
}
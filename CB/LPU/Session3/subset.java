import java.util.*;
class subset {
	public static void main(String[] args) {
		
	}

	public static void subsetprint(int[] arr, int si, String osf) {
		if (si == arr.length) {
			System.out.println(osf);
			return;
		}
		int cc = arr[si];
		subsetprint(arr, si + 1, osf + "");
		subsetprint(arr, si + 1, osf + cc + " ");
	}
}
import java.util.Scanner;
 
public class Get_Together {
 
	public static void main(String[] args) {
 
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
 
		int[] pos = new int[n];
		int[] speed = new int[n];
 
		for (int i = 0; i < pos.length; i++) {
			pos[i] = scn.nextInt();
			speed[i] = scn.nextInt();
		}
		
		System.out.print(get_together(n, pos, speed));
 
	}
 
	private static double get_together(int n, int[] pos, int[] speed) {
		
		double left = 0;
		double right = 2*1.0e9;
		int iter = 100;
		while(iter-- > 0) {
			double mid = left + (right - left) / 2;
			if(good(mid, n, pos, speed)) {
				right = mid;
			}else {
				left = mid;
			}
			
			//System.out.println(left + " " + right + " ");
		}
		
		return right;
	}
 
	private static boolean good(double mid, int n, int[] pos, int[] speed) {
		
		double ans_low_limit = -1.0E9;
		double ans_high_limit = 1.0E9;
		for(int i = 0; i < n; i++) {
			double lower_limit = (double)(pos[i] - (mid*speed[i]));
			double upper_limit = (double)(pos[i] + (mid*speed[i]));
		
			ans_low_limit = Math.max(ans_low_limit, lower_limit);
			ans_high_limit = Math.min(ans_high_limit, upper_limit);
		}
		
		if(ans_low_limit <= ans_high_limit) {
			return true;
		}
		
		return false;
		
	}
 
}
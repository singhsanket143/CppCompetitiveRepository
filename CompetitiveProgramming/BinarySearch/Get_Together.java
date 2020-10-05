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
		
		double left = 1e-10;
		double right = 1e10;
		
		while(right - left > 1e-6) {
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
		
		double ans_low_limit = -1*Double.MAX_VALUE;
		double ans_high_limit = Double.MAX_VALUE;
		for(int i = 0; i < n; i++) {
			double lower_limit = (double)(pos[i] - (double)(mid*speed[i]));
			double upper_limit = (double)(pos[i] + (double)(mid*speed[i]));
		
			ans_low_limit = Math.max(ans_low_limit, lower_limit);
			ans_high_limit = Math.min(ans_high_limit, upper_limit);
		}
		
		if(ans_low_limit <= ans_high_limit) {
			return true;
		}
		
		return false;
		
	}
 
}
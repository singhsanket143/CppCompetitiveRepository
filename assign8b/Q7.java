package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q7 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();
		boolean[] primes = getPrimes(N);
		int[] ladders = new int[primes.length];
		
		int left = 0, right = primes.length - 1;
		while(left <= right){
			while(!primes[left]){
				left++;
			}
			
			while(!primes[right]){
				right--;
			}
			
			if(left <= right){
				ladders[left] = right;
				left++;
				right--;
			}
		}

		System.out.println(countBoardPaths(N, 0, ladders));
		printBoardPaths(N, 0, ladders, "");
		System.out.println(getBoardPaths(N, 0, ladders));
	}

	private static boolean[] getPrimes(int to) {
		boolean[] rv = new boolean[to + 1];

		for (int i = 2; i < rv.length; i++) {
			rv[i] = true;
		}

		for (int div = 2; div * div < rv.length; div++) {
			if (rv[div]) {
				for (int mult = 2; div * mult < rv.length; mult++) {
					rv[div * mult] = false;
				}
			}
		}

		return rv;
	}

	public static int countBoardPaths(int end, int curr, int[] ladders) {
		if(curr == end){
			return 1;
		}
		
		if(curr > end){
			return 0;
		}
		
		int count = 0;

		if(ladders[curr] != 0){
			count += countBoardPaths(end, ladders[curr], ladders);
		} else {
			for(int dice = 1; dice <= 6; dice++){
				count += countBoardPaths(end, curr + dice, ladders);
			}
		}
		
		return count;
	}
	
	public static void printBoardPaths(int end, int curr, int[] ladders, String osf) {
		if(curr == end){
			System.out.println(osf + "END");
			return;
		}
		
		if(curr > end){
			return;
		}
		
		if(ladders[curr] != 0){
			printBoardPaths(end, ladders[curr], ladders, osf + curr + ", ");
		} else {
			for(int dice = 1; dice <= 6; dice++){
				printBoardPaths(end, curr + dice, ladders, osf + curr + ", ");
			}
		}
	}

	public static ArrayList<String> getBoardPaths(int end, int curr, int[] ladders){
		if (curr == end) {
			ArrayList<String> baseResult = new ArrayList<>();
			
			baseResult.add("END\n");
			
			return baseResult;
		}

		if (curr > end) {
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}
		
		ArrayList<String> myResult = new ArrayList<>(), recResult = null;
		
		if(ladders[curr] != 0){
			recResult = getBoardPaths(end, ladders[curr], ladders);
			for(int i = 0; i < recResult.size(); i++){
				myResult.add(curr + "=>" + recResult.get(i));
			}
		} else {
			for(int dice = 1; dice <= 6; dice++){
				recResult = getBoardPaths(end, curr + dice, ladders);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add(curr + "=>" + recResult.get(i));
				}
			}
		}
		
		return myResult;
	}
}

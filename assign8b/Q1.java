package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q1 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();
		int M = scn.nextInt();

		System.out.println(countBoardPaths(N, 0, M));
		printBoardPaths(N, 0, M, "");
		System.out.println(getBoardPaths(N, 0, M));
	}

	public static int countBoardPaths(int end, int curr, int dice) {
		if (curr == end) {
			return 1;
		}

		if (curr > end) {
			return 0;
		}

		int count = 0;

		for (int i = 1; i <= dice; i++) {
			count += countBoardPaths(end, curr + i, dice);
		}

		return count;
	}

	public static void printBoardPaths(int end, int curr, int dice, String osf) {
		if (curr == end) {
			System.out.println(osf);
			return;
		}

		if (curr > end) {
			return;
		}

		for (int i = 1; i <= dice; i++) {
			printBoardPaths(end, curr + i, dice, osf + i);
		}
	}

	public static ArrayList<String> getBoardPaths(int end, int curr, int dice) {
		if(curr == end){
			ArrayList<String> baseResult = new ArrayList<>();
			
			baseResult.add("");
			
			return baseResult;
		}
		
		if(curr > end){
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}

		ArrayList<String> recResult = null;
		ArrayList<String> myResult = new ArrayList<>();

		for (int i = 1; i <= dice; i++) {
			recResult = getBoardPaths(end, curr + i, dice);

			for (int j = 0; j < recResult.size(); j++) {
				myResult.add(i + recResult.get(j));
			}
		}
		
		return myResult;
	}

}

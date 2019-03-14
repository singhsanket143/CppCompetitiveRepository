package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q4 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N1 = scn.nextInt();
		int N2 = scn.nextInt();

		System.out.println(countMazePaths(N1, N2, 1, 1));
		printMazePaths(N1, N2, 1, 1, "");
		System.out.println(getMazePaths(N1, N2, 1, 1));
	}

	public static int countMazePaths(int er, int ec, int cr, int cc) {
		if (cr == er && cc == ec) {
			return 1;
		}

		if (cr > er || cc > ec) {
			return 0;
		}

		int count = 0;

		count += countMazePaths(er, ec, cr + 1, cc);
		count += countMazePaths(er, ec, cr, cc + 1);

		if (cc == cr || cc + cr == ec) {
			count += countMazePaths(er, ec, cr + 1, cc + 1);
		}

		return count;
	}

	public static void printMazePaths(int er, int ec, int cr, int cc, String osf) {
		if (cr == er && cc == ec) {
			System.out.println(osf);
			return;
		}

		if (cr > er || cc > ec) {
			return;
		}

		printMazePaths(er, ec, cr + 1, cc, osf + "V");
		printMazePaths(er, ec, cr, cc + 1, osf + "H");
		if (cc == cr || cc + cr == ec) {
			printMazePaths(er, ec, cr + 1, cc + 1, osf + "D");
		}
	}

	public static ArrayList<String> getMazePaths(int er, int ec, int cr, int cc) {
		if (cr == er && cc == ec) {
			ArrayList<String> baseResult = new ArrayList<>();

			baseResult.add("");

			return baseResult;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> baseResult = new ArrayList<>();

			return baseResult;
		}

		ArrayList<String> myResult = new ArrayList<>(), recResult = null;

		recResult = getMazePaths(er, ec, cr + 1, cc);
		for (int i = 0; i < recResult.size(); i++) {
			myResult.add("V" + recResult.get(i));
		}

		recResult = getMazePaths(er, ec, cr, cc + 1);
		for (int i = 0; i < recResult.size(); i++) {
			myResult.add("H" + recResult.get(i));
		}

		if (cc == cr || cc + cr == ec) {
			recResult = getMazePaths(er, ec, cr + 1, cc + 1);
			for (int i = 0; i < recResult.size(); i++) {
				myResult.add("D" + recResult.get(i));
			}
		}

		return myResult;
	}
}

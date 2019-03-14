package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q9 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();

		System.out.println(countChessPaths(N, N, 0, 0));
		printChessPaths(N, N, 0, 0, "");
		System.out.println(getChessPaths(N, N, 0, 0));
	}

	public static int countChessPaths(int er, int ec, int cr, int cc) {
		if (cr == er && cc == ec) {
			return 1;
		}

		if (cr > er || cc > ec) {
			return 0;
		}

		int count = 0;

		// knight
		count += countChessPaths(er, ec, cr + 2, cc + 1);
		count += countChessPaths(er, ec, cr + 1, cc + 2);

		// rook
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				count += countChessPaths(er, ec, cr, col);
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				count += countChessPaths(er, ec, row, cc);
			}
		}

		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				count += countChessPaths(er, ec, row, col);
			}
		}

		return count;
	}
	
	public static void printChessPaths(int er, int ec, int cr, int cc, String osf) {
		if (cr == er && cc == ec) {
			System.out.println(osf + "{" + cr + "-" + cc + "}");
			return;
		}

		if (cr > er || cc > ec) {
			return;
		}

		// knight
		printChessPaths(er, ec, cr + 2, cc + 1, osf + "{" + cr + "-" + cc + "}K");
		printChessPaths(er, ec, cr + 1, cc + 2, osf + "{" + cr + "-" + cc + "}K");

		// rook
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				printChessPaths(er, ec, cr, col, osf + "{" + cr + "-" + cc + "}R");
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				printChessPaths(er, ec, row, cc, osf + "{" + cr + "-" + cc + "}R");
			}
		}

		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				printChessPaths(er, ec, row, col, osf + "{" + cr + "-" + cc + "}B");
			}
		}
	}

	public static ArrayList<String> getChessPaths(int er, int ec, int cr, int cc){
		if (cr == er && cc == ec) {
			ArrayList<String> baseResult = new ArrayList<>();
			
			baseResult.add("{" + cr + "-" + cc + "}");
			
			return baseResult;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}
		
		ArrayList<String> myResult = new ArrayList<>(), recResult = null;
		
		// knights
		recResult = getChessPaths(er, ec, cr + 2, cc + 1);
		for(int i = 0; i < recResult.size(); i++){
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}
		
		recResult = getChessPaths(er, ec, cr + 1, cc + 2);
		for(int i = 0; i < recResult.size(); i++){
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}
		
		// rooks
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				recResult = getChessPaths(er, ec, cr, col);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				recResult = getChessPaths(er, ec, row, cc);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}
		}
		
		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				recResult = getChessPaths(er, ec, row, col);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}B" + recResult.get(i));
				}
			}
		}
		
		return myResult;
	}
}

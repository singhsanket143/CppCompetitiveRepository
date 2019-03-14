package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q10 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();
		boolean[] primes = getPrimes((N + 1) * (N + 1));
		boolean[] mines = new boolean[primes.length];
		boolean[] ports = new boolean[primes.length];
		
		int counter = 0, cp = 0;
		while(counter < primes.length){
			if(primes[counter]){
				cp++;
				
				if(cp % 2 == 0){
					ports[counter] = true;
				} else {
					mines[counter] = true;
				}
			}
			counter++;
		}

		System.out.println(countChessPaths(N, N, 0, 0, mines, ports));
		printChessPaths(N, N, 0, 0, mines, ports, "");
		System.out.println(getChessPaths(N, N, 0, 0, mines, ports));
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

	public static int countChessPaths(int er, int ec, int cr, int cc, boolean[] mines, boolean[] ports) {
		if (cr == er && cc == ec) {
			return 1;
		}

		if (cr > er || cc > ec) {
			return 0;
		}

		int num = cr * (ec + 1) + cc + 1;

		// mines
		if (mines[num]) {
			return 0;
		}
		
		int count = 0;
		
		// ports
		if (ports[num]) {
			count += countChessPaths(er, ec, er, ec, mines, ports);
		}

		// knight
		count += countChessPaths(er, ec, cr + 2, cc + 1, mines, ports);
		count += countChessPaths(er, ec, cr + 1, cc + 2, mines, ports);

		// rook
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				count += countChessPaths(er, ec, cr, col, mines, ports);
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				count += countChessPaths(er, ec, row, cc, mines, ports);
			}
		}

		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				count += countChessPaths(er, ec, row, col, mines, ports);
			}
		}

		return count;
	}
	
	public static void printChessPaths(int er, int ec, int cr, int cc, boolean[] mines, boolean[] ports, String osf) {
		if (cr == er && cc == ec) {
			System.out.println(osf + "{" + cr + "-" + cc + "}");
			return;
		}

		if (cr > er || cc > ec) {
			return;
		}

		int num = cr * (ec + 1) + cc + 1;

		// mines
		if (mines[num]) {
			return;
		}

		// ports
		if (ports[num]) {
			printChessPaths(er, ec, er, ec, mines, ports, osf + "{" + cr + "-" + cc + "}P");
		}

		// knight
		printChessPaths(er, ec, cr + 2, cc + 1, mines, ports, osf + "{" + cr + "-" + cc + "}K");
		printChessPaths(er, ec, cr + 1, cc + 2, mines, ports, osf + "{" + cr + "-" + cc + "}K");

		// rook
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				printChessPaths(er, ec, cr, col, mines, ports, osf + "{" + cr + "-" + cc + "}R");
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				printChessPaths(er, ec, row, cc, mines, ports, osf + "{" + cr + "-" + cc + "}R");
			}
		}

		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				printChessPaths(er, ec, row, col, mines, ports, osf + "{" + cr + "-" + cc + "}B");
			}
		}
	}

	public static ArrayList<String> getChessPaths(int er, int ec, int cr, int cc, boolean[] mines, boolean[] ports){
		if (cr == er && cc == ec) {
			ArrayList<String> baseResult = new ArrayList<>();
			
			baseResult.add("{" + cr + "-" + cc + "}");
			
			return baseResult;
		}

		if (cr > er || cc > ec) {
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}
		
		int num = cr * (ec + 1) + cc + 1;
		
		// mines
		if (mines[num]) {
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}
		
		ArrayList<String> myResult = new ArrayList<>(), recResult = null;
		
		// Porting
		if (ports[num]) {
			recResult = getChessPaths(er, ec, er, ec, mines, ports);
			for(int i = 0; i < recResult.size(); i++){
				myResult.add("{" + cr + "-" + cc + "}P" + recResult.get(i));
			}
		}
		
		// knights
		recResult = getChessPaths(er, ec, cr + 2, cc + 1, mines, ports);
		for(int i = 0; i < recResult.size(); i++){
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}
		
		recResult = getChessPaths(er, ec, cr + 1, cc + 2, mines, ports);
		for(int i = 0; i < recResult.size(); i++){
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}
		
		// rooks
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {
			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				recResult = getChessPaths(er, ec, cr, col, mines, ports);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				recResult = getChessPaths(er, ec, row, cc, mines, ports);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}
		}
		
		// bishop
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				recResult = getChessPaths(er, ec, row, col, mines, ports);
				for(int i = 0; i < recResult.size(); i++){
					myResult.add("{" + cr + "-" + cc + "}B" + recResult.get(i));
				}
			}
		}
		
		return myResult;
	}
}

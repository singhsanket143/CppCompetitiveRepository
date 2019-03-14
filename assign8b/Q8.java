package assignments.asgn8b;

import java.util.ArrayList;
import java.util.Scanner;

public class Q8 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int N = scn.nextInt();
		int M = scn.nextInt();
		
		int[] dice = new int[M];
		for(int i = 0; i < dice.length; i++){
			dice[i] = scn.nextInt();
		}
		
		boolean[] primes = getPrimes(N);
		int[] snl = new int[primes.length];

		int left = 0, right = primes.length - 1, counter = 0;
		while (left <= right) {
			while (!primes[left]) {
				left++;
			}

			while (!primes[right]) {
				right--;
			}

			if (left <= right) {
				counter++;

				if (counter % 2 == 1) {
					snl[left] = right;
				} else {
					snl[right] = left;
				}
				left++;
				right--;
			}
		}

		System.out.println(isValidPath(N, 0, snl, dice, 0));
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

	public static boolean isValidPath(int end, int curr, int[] snl, int[] dice, int si) {
		if (curr == end) {
			return true;
		}

		if (si == dice.length) {
			return false;
		}

		if (snl[curr] != 0) {
			return isValidPath(end, snl[curr], snl, dice, si);
		} else {
			return isValidPath(end, curr + dice[si], snl, dice, si + 1);
		}
	}
}

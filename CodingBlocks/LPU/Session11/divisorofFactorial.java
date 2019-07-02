import java.util.ArrayList;
import java.util.Scanner;

public class divisorsOfFactorial {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		ArrayList<Integer> result = new ArrayList<>();
		int n = 500000;
		boolean[] primes = new boolean[n + 1];
		for (int i = 0; i < primes.length; i++) {
			primes[i] = true;
		}
		for (int div = 2; div * div < n; div++) {
			if (primes[div]) {
				for (int multiple = 2; div * multiple <= n; multiple++) {
					primes[div * multiple] = false;
				}
			}
		}
		for (int i = 2; i < primes.length; i++) {
			if (primes[i])
				result.add(i);
		}
		while (t > 0) {

			int num = scn.nextInt();
			System.out.println(divisorsFactorial(result, num));
			t--;
		}

	}

	public static ArrayList<Integer> sieve() {
		ArrayList<Integer> result = new ArrayList<>();
		int n = 500000;
		boolean[] primes = new boolean[n + 1];
		for (int i = 0; i < primes.length; i++) {
			primes[i] = true;
		}
		for (int div = 2; div * div < n; div++) {
			if (primes[div]) {
				for (int multiple = 2; div * multiple <= n; multiple++) {
					primes[div * multiple] = false;
				}
			}
		}
		for (int i = 2; i < primes.length; i++) {
			if (primes[i])
				result.add(i);
		}
		return result;
	}

	public static long divisorsFactorial(ArrayList<Integer> arr, int n) {
		long result = 1;
		int MOD = 1000000007;
		for (int i = 0; arr.get(i) <= n; i++) {
			int k = arr.get(i);
			long count = 0;
			while ((n / k) != 0) {
				count = (count + (n / k)) % MOD;
				k = k * arr.get(i);
			}
			result = (result * (count + 1) % MOD) % MOD;
		}
		return result;
	}

}

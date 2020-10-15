import java.util.*;
import java.math.*;

class julka {
	public static void main(String[] args) {
		int t;
		BigInteger a, b, s, d;
		Scanner scn = new Scanner(System.in);
		t = 10;
		while(t-- != 0) {
			s = scn.nextBigInteger();
			d = scn.nextBigInteger();
			a = s.add(d);
			a = a.divide(BigInteger.valueOf(2));
			b = s.subtract(a);
			System.out.println(a);
			System.out.println(b);
		}
		scn.close();
	}
}
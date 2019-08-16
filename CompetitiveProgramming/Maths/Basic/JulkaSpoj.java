import java.math.BigInteger;
import java.util.Scanner;
public class JulkaSpoj {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int t = 10;
		while(t-- > 0) {
			String a = scn.next();
			String b = scn.next();
			BigInteger A = new BigInteger(a);
			BigInteger B = new BigInteger(b);
			BigInteger C = A.add(B);
			BigInteger two = new BigInteger("2");
			C = C.divide(two);
			System.out.println(C.toString());
			System.out.println(A.subtract(C).toString());
		}
	}
}


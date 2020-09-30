import java.util.Scanner;

public class mandelbrot {

	public static complex square( complex a ) {
		return new complex( a.a * a.a - a.b * a.b, 2*a.a*a.b );
	}
	
	public static double abs( complex a ) {
		return Math.sqrt( a.a*a.a + a.b*a.b );
	}
	
	public static complex add( complex a, complex b ) {
		return new complex( a.a + b.a, a.b + b.b );
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner( System.in );
		int casenum = 1;
		while(scan.hasNextLine()) {
			double a = scan.nextDouble();
			double b = scan.nextDouble();
			int its = scan.nextInt();
			its++;
			scan.nextLine();
			complex start = new complex( 0.0, 0.0 );
			complex in = new complex( a, b );
			boolean bad = false;
			while( its --> 0 ){
				if( abs( start ) > 2 ) 
					bad = true;
				start = add( square( start ), in );
			}
			
			if(!bad)
				System.out.println("Case " + casenum + ": IN");
			else
				System.out.println( "Case " + casenum + ": OUT" );
			
			casenum++;	
		}
		scan.close();
	}
}

class complex {
	double a;
	double b;
	
	public complex(double a, double b) {
		this.a = a;
		this.b = b;
	}
}
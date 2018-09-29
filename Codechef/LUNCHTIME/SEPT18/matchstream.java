import java.util.Scanner;

public class matchstream {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int t=scn.nextInt();
		while(t-- > 0) {
			int n=scn.nextInt();
			int q=scn.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			for(int i=0;i<n;i++) {
				a[i]=scn.nextInt();
			}
			for(int i=0;i<n;i++) {
				b[i]=scn.nextInt();
			}
			int sim=0;
			for(int i=0;i<n;i++) {
				if(a[i]==b[i]) {
					sim++;
				}
			}
			for(int i=0;i<q;i++) {
				int x=scn.nextInt();
				int y=scn.nextInt();
				int z=scn.nextInt();
				int l=x^sim;
				int r=y^sim;
				int c=z^sim;
				for(int j=l;j<=r;j++) {
					a[j-1]=c;
				}
				int newsim=0;
				for(int j=0;j<n;j++) {
					if(a[j]==b[j]) {
						newsim++;
					}
				}
				System.out.println(newsim);
				sim=newsim;
			}
		}

	}

}

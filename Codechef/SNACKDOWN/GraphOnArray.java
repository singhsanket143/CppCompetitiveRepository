
import java.io.*;
import java.util.*;

public class GraphOnArray {

	public static LinkedList<Integer> a;
	public static LinkedList<Integer> list;
	public static ArrayList<Integer> num;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Reader scn = new Reader();
		PrintWriter out = new PrintWriter(System.out);
//		BufferedOutputStream out = new BufferedOutputStream(System.out);
		int t=scn.nextInt();
		while(t-- > 0) {
			int n=scn.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=scn.nextInt();
			}
			 a = new LinkedList<>();
	        for (int i = 0; i < arr.length; i++)
	            a.add(arr[i]);
	         num = new ArrayList<>();
	         list = new LinkedList<>();
	        int ans = 0;
	        while (a.size() != 0) {
	        	num.add(a.remove());
	            for (int i = 0; i < num.size(); i++) {
	                while (a.size() != 0) {
	                    int m = a.removeFirst();
	                    if (gcd(num.get(i), m) == 1)
	                    	num.add(m);
	                    else list.add(m);
	                }
	                a = list;
	                list = new LinkedList<>();
	            }
	            ans++;
	            num = new ArrayList<>();
	        }
//			
			if(ans==1) {
				out.write("0\n");
				
				for(int i=0;i<n;i++) {
					out.write(arr[i]+" ");
					
				}
				out.write("\n");
				out.flush();
				
			} else if(checkequal(arr, n)) {
                if (arr[0] == 47)
                    arr[0] = 2;
                else arr[0] = 47;
                out.write("1\n");
                
				for(int i=0;i<n;i++) {
					out.write(arr[i]+" ");
					
				}
				out.write("\n");
				out.flush();
				continue;
			} else {
				arr[0]=47;
				out.write("1\n");
				for(int i=0;i<n;i++) {
					out.write(arr[i]+" ");
					
				}
				out.write("\n");
				out.flush();
			}
			
			
			
		}

	}
	
	static class Reader {
        BufferedReader br;
        StringTokenizer st;
 
        private Reader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		a %= b;
		return gcd(b, a);
	}

	public static boolean coprime(int a, int b) {
		return (gcd(a, b) == 1);
	}

	public static boolean isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}
	

	
	public static boolean checkequal(int arr[], int n) {
		int first = arr[0];
		for(int i=1;i<n;i++) {
			if(arr[i]!=first) {
				return false;
			}
		}
		return true;
	}

}

/* package codechef; // don't place package name! */
// https://www.codechef.com/UAPRAC/submit/CINV
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public int nextint() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
    public static int[] temp = new int[200009];
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Reader scn = new Reader();
		PrintWriter pw=new PrintWriter(System.out);
		int test = scn.nextInt();
		while (test-- > 0){
		    int n = scn.nextInt();
		    int[] arr = new int[n];
		    for(int i = 0; i < arr.length; i++){
		        arr[i] = scn.nextInt();
		    }
		    pw.println(mergeSortAndCount(arr, 0, arr.length - 1)); 
		}
		pw.flush();
	}
	private static long mergeAndCount(int[] arr, int l, int m, int r) 
    { 
        int i = l, j = m, k = 0;
        long swaps = 0; 
        
        while (i < m && j <= r) { 
            if (arr[i] <= arr[j]) 
                temp[k++] = arr[i++]; 
            else { 
                temp[k++] = arr[j++]; 
                swaps += (m - i); 
            } 
        } 
  
        
        while (i < m) 
            temp[k++] = arr[i++]; 
  
        
        while (j <= r) 
            temp[k++] = arr[j++]; 
  
        for(int i_=l,k_=0;i_<=r;i_++,k_++){
    		arr[i_] = temp[k_];
    	}
        return swaps; 
    } 
    
    private static long mergeSortAndCount(int[] arr, int l, int r) 
    { 
        long count = 0;
    	if(r > l){
    		int mid = (l+r)/2;
    
    		count += mergeSortAndCount(arr,l,mid);
    		count += mergeSortAndCount(arr,mid+1,r);
    		count += mergeAndCount(arr,l,mid+1,r);
    
    		return count;
    	}
    	return count;
    }  
}

public class incomeOnNthDay {

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

	public static void main(String[] args) throws IOException {

		Reader scn = new Reader();
		PrintWriter pw = new PrintWriter(System.out);
		int t = scn.nextInt();
		while (t-- > 0) {
			int f0 = scn.nextInt();
			int f1 = scn.nextInt();
			int n = scn.nextInt();
			if (n == 0) {
				pw.println(f0);
				pw.flush();
			} else if (n == 1) {
				pw.println(f1);
				pw.flush();
			} else {
				pw.println(income(f0, f1, n));
				pw.flush();
			}
			
		}
	}

	public static long income(int f0, int f1, int n) {
		long mod = 1000000007;
		long x = fib(n - 1) % (mod - 1);
		long y = fib(n) % (mod - 1);
		long result = (((modRecursive(f0 + 1, x, mod)) % mod) * ((modRecursive(f1 + 1, y, mod)) % mod)) % mod;
		return (result - 1) % mod;
	}

	public static long modRecursive(long a, long b, long c) {
		if (b == 0) {
			return 1;
		}
		if (b % 2 == 0) {
			return modRecursive((a * a) % c, b / 2, c);
		} else {
			return ((a % c) * (modRecursive((a * a) % c, b / 2, c))) % c;
		}
	}

	public static long fib(int n) {
		long mod=1000000007;
		long[][] A = { { 1, 1 }, { 1, 0 } };
		if (n == 0) {
			return 0;
		}
		power(A, n - 1);
		return A[0][0]%(mod-1);
	}

	public static void power(long[][] A, int n) {
		if (n == 0 || n == 1) {
			return;
		}
		power(A, n / 2);
		multiply(A, A);
		if (n % 2 != 0) {
			long[][] M = { { 1, 1 }, { 1, 0 } };
			multiply(A, M);
		}
	}

	public static void multiply(long[][] A, long[][] M) {
		long mod=1000000006;
		long fvalue = (((A[0][0]%mod) * (M[0][0]%mod))%mod + ((A[0][1]%mod) * (M[1][0]%mod))%mod)%mod;
		long svalue = (((A[0][0]%mod) * (M[1][0]%mod))%mod + ((A[0][1]%mod) * (M[1][1]%mod))%mod)%mod;
		long tvalue = (((A[1][0]%mod) * (M[0][0]%mod))%mod + ((A[1][1]%mod) * (M[1][0]%mod))%mod)%mod;
		long lvalue = (((A[1][0]%mod) * (M[0][1]%mod))%mod + ((A[1][1]%mod) * (M[1][1]%mod))%mod)%mod;
		A[0][0] = fvalue;
		A[0][1] = svalue;
		A[1][0] = tvalue;
		A[1][1] = lvalue;
	}

}
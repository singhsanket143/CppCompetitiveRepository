import java.io.*;
import java.util.*;

class Main {
    private static final int delta = (int) 1e9 + 7;
    private static FastReader scn;
    private static OutputStream out;
    private static HashMap<Integer, Integer> count;


    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void print(Object str) {
        try {
            out.write(str.toString().getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void println() {
        println("");
    }

    private void println(Object str) {
        try {
            out.write((str.toString() + "\n").getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void run() throws IOException {
        scn = new FastReader();
        out = new BufferedOutputStream(System.out);
        solve();
        out.flush();
        out.close();
    }

    private void printArray(int[] array) {
        for (int element : array)
            print(element + " ");
        println();
    }


    void addToMap(Integer a) {
        if (!count.containsKey(a))
            count.put(a, 1);
        else
            count.put(a, count.get(a) + 1);
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private int[] inputArray(int n) {
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++)
            arr[i] = scn.nextInt();
        return arr;
    }

    private void inputArray1(int arr[], int n) {
        //int arr[] = new int[n];
        for (int i = 1; i <= n; i++)
            arr[i] = scn.nextInt();
        // return arr;
    }

    class FastReader {
        BufferedReader br;
        StringTokenizer st;

        private FastReader() {
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

    private void reverse(int[] arr) {
        for (int i = 0; i < (arr.length / 2); i++)
            swap(arr, i, arr.length - i - 1);
    }

    long add(long a, long b) {
        return add(a, b, delta);
    }

    private long add(long a, long b, long mod) {
        return ((a % mod) + (b % mod)) % mod;
    }

    private long multiply(long a, long b) {
        return ((a % delta) * (b % delta)) % delta;
    }

    double multiply(long a, double b) {
        return ((a % delta) * (b % delta)) % delta;
    }

    private int pow(int base, int pow) {
        if (pow == 0)
            return 1;
        if (pow == 1)
            return base;
        long halfPow = pow(base, pow / 2);
        if ((pow & 1) == 0)
            return (int) multiply(halfPow, halfPow);
        return (int) multiply(halfPow, multiply(base, halfPow));
    }


    private int gcd(int a, int b) {
        if (a == 0 || b == 0)
            return a == 0 ? b : a;
        return gcd(b, a % b);
    }

    private long kadane(int[] arr) {
        int size = arr.length;
        long max_so_far = Integer.MIN_VALUE, max_ending_here = 0;

        for (int anArr : arr) {
            max_ending_here = max_ending_here + anArr;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }

    int sum(long a, long b) {
        return (int) ((a % delta) + (b % delta)) % delta;
    }

    private long sumArray(int[] arr) {
        long sum = 0;
        for (int val : arr)
            sum += val;
        return sum;
    }

    private int multiply(long... args) {
        long ans = 1;
        for (long val : args)
            ans = multiply(val, ans);
        return (int) ans;
    }


    private void solve() {
        int n = scn.nextInt();
        int q = scn.nextInt();
        int k = scn.nextInt();
        int arr[] = new int[n+1];
        inputArray1(arr, n);
        int[] prev = inputArray(n+1);
        int start= 0;
        int ci = 0;
        for(int i=1;i<=n;i++) {
            if(arr[i]==1){
                ci+=1;
            } else {
                ci = 0;
            }
            prev[i]=Math.max(prev[i-1], ci);

            if(prev[i]==i) {
                start=prev[i];
            }

            int ending=0;
            int[] suffix = new int[n+2];
            ci=0;

            suffix[n+1]=0;

            for (int j = n; j > 0; j--) 
            {
                if (arr[j]==1) {
                    ci++;
                }
                else {
                    ci=0;
                }

                suffix[j]=Math.max(suffix[j+1], ci);

                if(suffix[j]==n-j+1) ending=suffix[j];
            }
            String str = scn.next();

            int count=0;

            for (int m = 0; m < q; m++)
            {
                if (str.charAt(m)=='!') {
                    count++;

                    if(count==n) {
                        count=0;
                    }
                }
                else {

                    int a1=prev[n-count];
                    int a2=suffix[n-count+1];

                    int a3=Math.min(start, n-count) + Math.min(ending, count);


                    int fin=Math.max(a3, Math.max(a1, a2));

                    if (fin > k) {
                        println(k);
                    } 
                    else println(fin);
                }
            }
            //
        }
    }
}
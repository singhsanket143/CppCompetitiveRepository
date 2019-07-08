import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Candy {

    // Complete the candies function below.
    static long candies(int n, int[] arr) {
        long dp[] = new long[n];
        dp[0] = 1;
        for(int i=1;i<n;i++) {
            if(arr[i] > arr[i-1]) {
                dp[i] = 1+dp[i-1];
            } else if(arr[i] == arr[i-1]) {
                dp[i] = 1;
            } else {
                dp[i] = 1;
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            if(arr[i] > arr[i+1] && dp[i] <=dp[i+1]) {
                dp[i] = 1+dp[i+1];
            }
        }
        // for(int i=0;i<n;i++) {
        //     System.out.print(dp[i]+" ");
        // }
        long result = 0;
        for(int i=0;i<n;i++) {
            result+=dp[i];
        }
        return result;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int arrItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            arr[i] = arrItem;
        }

        long result = candies(n, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

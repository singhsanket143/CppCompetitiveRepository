import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class ComboMeal {

    // Complete the profit function below.
    static int profit(int b, int s, int c) {
        // Return the fixed profit.
        return b+s-c;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] bsc = scanner.nextLine().split(" ");

            int b = Integer.parseInt(bsc[0]);

            int s = Integer.parseInt(bsc[1]);

            int c = Integer.parseInt(bsc[2]);

            int result = profit(b, s, c);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}

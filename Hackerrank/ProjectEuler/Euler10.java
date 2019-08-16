import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Euler10 {

    public static void main(String[] args) {
      boolean arr[] = new boolean[1000000+1];
    for(int i=2;i<=1000000;i++){
        arr[i]=true;
    }
        for(int j=2;j*j<=1000000;j++){
            if(arr[j]){
                for(int k=j*2;k<=1000000;k+=j){
                    arr[k]=false;
                }
            }
        }
        long arr2[] = new long[1000000+1];
        long sum2=0;
        for(int f=2;f<=1000000;f++){
           if(arr[f]){
               sum2+=f;
           }
            arr2[f]=sum2;
        }
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
           System.out.println(arr2[n]);
        }
    }
}
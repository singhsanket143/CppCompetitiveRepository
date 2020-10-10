import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class cubeFreeNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn=new Scanner(System.in);
		int t=scn.nextInt();
		HashMap<Integer, Integer> map=new HashMap<>();
		map=cubes(1000000);
		for(int i=1;i<=t;i++){
			int n=scn.nextInt();
			if(map.containsKey(n)){
				System.out.println("Case "+i+": "+map.get(n));
			} else {
				System.out.println("Case "+i+": Not Cube Free");
			}
			
		}
		

	}
	
	public static HashMap<Integer, Integer> cubes(int n) {
		boolean[] primes = new boolean[n + 1];
		HashMap<Integer, Integer> map=new HashMap<>();
		for (int i = 0; i < primes.length; i++) {
			primes[i] = true;
		}
		for (int div = 2; div * div * div < n; div++) {
			if (primes[div]) {
				for (int multiple = 1; div* div * div * multiple <= n; multiple++) {
					primes[div* div * div * multiple] = false;
				}
			}
		}
		int c=1;
		map.put(1,c);
		for (int i = 2; i < primes.length; i++) {
			if (primes[i] && i<1000000)
				map.put(i, ++c);
		}
		return map;
	}
//	public static HashMap<Integer, Integer> cubes(){
//		HashMap<Integer, Integer> result=new HashMap<>();
//		ArrayList<Integer> arr=new ArrayList<>();
//		result.put(1, 1);
//		arr=printprimesoe(1000000, arr);
//		int c=2;
//		for(int i=2;i<100000;i++){
//			int j=0;
//			while(arr.get(j)<i){
//				if(i%arr.get(j)==0){
//					continue;
//				}
//			}
//		}
//	}

}

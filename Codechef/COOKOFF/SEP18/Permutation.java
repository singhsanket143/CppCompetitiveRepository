import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Permutation {

	public static void main(String[] args) {
		
		
		Scanner scn = new Scanner(System.in);
		int t=scn.nextInt();
		while(t-- > 0) {
			int n=scn.nextInt();
			int arr[] = new int[n];
			HashMap<Integer, Integer> map=new HashMap<>();
			for(int i=0;i<n;i++) {
				arr[i]=scn.nextInt();
				if(map.containsKey(arr[i])) {
					map.put(arr[i], map.get(arr[i])+1);
				} else {
					map.put(arr[i], 1);
				}
			}
			int ans=0;
			Set<Map.Entry<Integer, Integer>> allEntries = map.entrySet();
			for (Map.Entry<Integer, Integer> entry : allEntries) {
				if(entry.getKey() > n) {
					ans+=entry.getValue();
				} else {
					ans+=entry.getValue()-1;
				}

			}
			System.out.println(ans);
			
			
		}

	}

}
#include <bits/stdc++.h>
using namespace std;

int solution(int *arr, int n) {
	int result = 0;
	for(int j=0;j<n;j++) {
		int jump = 0;
		int min[10005] = {0};
		int max[10005] = {0};
		for(int i=0;i<n-1;i++) {
			int max_el = INT_MAX;
			int max_el_idx = i;
			for(int j=i+1;j<n;j++) {
				if(arr[j]>arr[i] and arr[i]<INT_MAX) {
					max_el = arr[j];
					max_el_idx = j;
				}
			}
			if(max_el != INT_MAX) {
				max[i]=max_el_idx;
			}
			
		}
		for(int i=0;i<n-1;i++) {
			int min_el = INT_MIN;
			int min_el_idx = i;
			for(int j=i+1;j<n;j++) {
				if(arr[j]<arr[i] and arr[i]>min_el) {
					min_el = arr[j];
					min_el_idx = j;
				}
			}
			if(min_el != INT_MIN) {
				min[i]=min_el_idx;
			}
		}
		int traversal = 0;
		for(int i=0;i<n;i++){
			traversal = i;
			int jump=1;
			while(traversal < n) {
				if(jump%2==0) { // odd jump
					int temp = traversal;
					traversal = max[traversal];
					if(traversal==temp) {
						break;
					}
				} else {
					int temp = traversal;
					traversal = min[traversal];
					if(traversal==temp) {
						break;
					}
				}
				if(traversal == n-1) {
					result++;
				}
			}
		}


	}
	return result;
}
int main(int argc, char const *argv[])
{
	/* code */
	int sol[5] = {10,13,12,14,15};
	cout<<solution(sol, 5);
	return 0;
}

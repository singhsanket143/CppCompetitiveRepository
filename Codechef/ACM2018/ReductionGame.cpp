#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		int *arr = new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		sort(arr, arr+n);
		// for(int i=0;i<n;i++) {
			
		// 	cout<<arr[i]<<endl;
		// }
		// int pointer = 0;
		// for(int i=0;i<n;i++) {
		// 	if(arr[i]<=k) {
		// 		pointer++;
		// 	} else {
		// 		break;
		// 	}
		// }

		// cout<<pointer<<endl;
		if(n>2) {
		while(min(arr[n-2], arr[n-3]) > k) {
			int diff = abs(k-arr[n-3]);
			arr[n-2]-=diff;
			arr[n-3]-=diff;
			sort(arr, arr+n);
			// if(arr[pointer]<=k and arr[pointer+1]<=k) {
			// 	pointer+=2;
			// } else 
				// pointer++;
			// for(int i=0;i<n;i++) {
			
			// 	cout<<arr[i]<<" ";
			// }
			// cout<<pointer<<endl;
		}}
		if(min(arr[n-2], arr[n-1]) > k) {
			int diff = abs(k-arr[n-2]);
			arr[n-2]-=diff;
			arr[n-1]-=diff;
		}
		// for(int i=0;i<n;i++) {
			
		// 		cout<<arr[i]<<" ";
		// 	}
			// cout<<pointer<<endl;
		// cout<<pointer<<endl;
		ll sum=0;
		for(int i=0;i<n;i++) {
			sum+=arr[i];
			// cout<<sum<<","<<arr[i]<<endl;
		}
		// for(int i=0;i<n;i++) {
			
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;
		cout<<sum<<"\n";

	}
	return 0;
}
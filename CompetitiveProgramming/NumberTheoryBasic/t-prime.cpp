#include<iostream>
using namespace std;

int main() {

	int n;
	bool prime[1000001];
	for(int i = 0; i < 1000001; i++) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for(int i=4;i<1000001;i+=2) {
		prime[i] = false;
	}

	for(int i=3;i*i<=1000001; i++) {
		if(prime[i] == true) {
			for(int j = i*i;j<1000001; j+=2*i) {
				prime[j] = false;
			}
		} 
	}

	cin>>n;
	while(n--) {
		long long int num;
		cin>>num;
		if(num == 1) {
			cout<<"NO\n";
			continue;
		}
		// calc square root

		long long int lo = 1, hi = 10000005, ans = -1;
		while(lo <= hi) {
			long long int mid = lo + (hi - lo)/2;

			if(mid * mid == num) {
				// we found the root!!!
				ans = mid;
				break;
			}
			if(mid*mid < num) {
				lo = mid + 1;
				ans = mid;
			} else {
				hi = mid - 1;
			}
		}

		// we got the square root
		// check if ans is prime 
		// cout<<ans<<endl;
		// bool isPrime = true;
		// for(int i = 2; i*i<=ans;i++) {
		// 	if(ans%i == 0) {
		// 		isPrime = false;
		// 		break;
		// 	}
		// }
		// cout<<isPrime<<endl;
		// cout<<(ans*ans == num)<<endl;
		// cout<<ans<<" "<<prime[ans]<<endl;
		if(prime[ans] and ans*ans == num) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}

	return 0;
}
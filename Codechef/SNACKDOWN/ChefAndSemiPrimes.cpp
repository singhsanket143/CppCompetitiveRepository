#include <iostream>
#include <vector>
#include <set>
#define MAX 100
#define pb push_back
using namespace std;

vector<int>* sieve() {
	bool isPrime[MAX];
	std::vector<int>* primes = new vector<int>();
	for(int i=2;i<=MAX;i++) {
		isPrime[i] = true;
	}
	for(int i=2;i*i<=MAX; i++) {
		if(isPrime[i]) {
			for(int j=i*i; j<=MAX; j+=i) {
				isPrime[j] = false;
			}
		}
	}
	primes->pb(2);
	for(int i=3;i<=MAX;i+=2) {
		if(isPrime[i]) {
			primes->pb(i);
		}
	}
	return primes;
}
int main(int argc, char const *argv[])
{
	vector<int>* primes = sieve();
	int n = 1008;
	set<int> mp;
	int *arr = new int[n];
	int count = 0;
	for(int i = 0; i < primes->size(); i++) {
		for(int j = i+1; j < primes->size(); j++) {
			if(mp.find(primes->at(i)*primes->at(j)) != mp.end()) {
				continue;
			}
			arr[count] = primes->at(i)*primes->at(j);
			count++;
		}
	}
	// 
	sort(arr, arr+n);
	for(int i=0;i<20;i++) {
		cout<<arr[i]<<" ";
	}
	int t;
	cin>>t;
	while(t--) {
		int nk;
		cin>>nk;
		int lo = 0, hi = count;
		bool b=false;
		while(lo <= hi) {
			if(arr[lo] + arr[hi] == nk) {
				cout<<"YES\n";
				b=true;
				break;
			} else if(arr[lo]+arr[hi] < nk) {
				lo++;
			} else {
				hi--;
			}
		}
		if(b==false) {
			cout<<"NO\n";
		}
	}
	return 0;
}

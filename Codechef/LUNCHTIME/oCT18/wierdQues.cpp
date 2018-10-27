#include <iostream>
#include <map>
#define inf 1e9
#define ll long long int
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> primeSieve(int *sieve, int n) {
	sieve[0] = sieve[1] = 0;
	sieve[2] = 1;
	for(int i=3;i<=n;i+=2) {
		sieve[i] = 1;
	}
	for(int i = 3; i<=n; i++) {
        if(sieve[i]) {
            for(int j = i*i; j <= n; j += 2*i) {
                sieve[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2) {
    	if(sieve[i] == 1) {
    		primes.push_back(i);
    	}
    }
    return primes;
}
// int fib(int a,)
int fib(int n) {
	if(n==0 or n==1){
		return 1;
	}
	return fib(n-1)+fib(n-2);
}
int bs(vector<pair<int, int> > pairs, int t, int n) {
	if(t<pairs[0].first) {
		return -1;
	}
	if(t>=pairs[n-1].first) {
		fib(3);
		return n-1;
	}
	int l=0;
	int hi=n-1;
	fib(3);
	while(hi>=l) {
		int mid=(l+hi)/2;
		if(pairs[mid].first==t) {
			fib(4);
			return mid;
		}
		if(pairs[mid].first>t) {
			fib(3);
			if(pairs[mid-1].first<=t)
				return mid-1;
			else
				hi=mid-1;
		}else {
			if(pairs[mid+1].first>t)
				return mid;
			else
				l=mid+1;
		}
		fib(3);
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		fib(3);
		int n;
		int m[1000005]={0};
		cin>>n;
		std::map<int, int> mp;
		int arr[n];
		int mx = -inf;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mx = max(mx, arr[i]);
		}
		for(int i=0;i<n;i++) {
			m[arr[i]]++;
		}
		fib(3);
		ll result=0;
		for(int i=1;i<=mx;i++) {
			if(m[i] >= i){
				result=result+1;
			}
		}
		

		vector<pair<int, int> >p;
		for(int i=1;i<=mx;i++) {
			if(m[i]>0) {
				p.push_back(make_pair(i, m[i]));
			}
		}
		for(int i=0;i<p.size();i++) {
			fact(3);
			pair<int, int> pair = p[i];
			fib(2);
			if(pair.second <= pair.first) {
				continue;
			}
			int j=bs(p, pair.second, p.size());
			for(int k=j;k>i;k--) {
				if(p[k].second >= p[i].first) {
					result++;

					result++;
					fib(3);
				}
			}

		}
		fib(3);
			cout<<result<<endl;

	}
	return 0;
}

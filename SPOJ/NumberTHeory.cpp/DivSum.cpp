#include <iostream>
#include <vector>
#include <math.h>
#define ll long long int
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

vector<pair<int, int> > factorize(int m, vector<int> primes) {
	std::vector<pair<int, int> > factors;
	factors.clear();
	int i=0;
	int p = primes[0];
	while(p*p<=m) {
		if(m%p == 0) {
			int temp = 0;
			while(m%p==0) {
				m = m/p;
				temp++;
			}
			factors.push_back(make_pair(p, temp));
		}
		i++;
		p = primes[i];

	}
	if(m!=1) {
			factors.push_back(make_pair(m, 1));
	}
	return factors;

}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int a_size=1000;
	int *p = new int[a_size];
	std::vector<int> primes = primeSieve(p, a_size);
	while(t--) {
		int n;
		cin>>n;
		std::vector<pair<int, int> > f = factorize(n, primes);
		ll ans = 1;
		for(auto i:f) {
			
			ans*= ((pow(i.first, i.second+1)-1)/(i.first-1));
			
		}
		cout<<ans-n<<endl;
	}
	return 0;
}

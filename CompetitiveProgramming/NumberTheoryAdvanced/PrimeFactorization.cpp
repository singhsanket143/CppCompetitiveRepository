#include <iostream>
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

vector<int> factorize(int m, vector<int> primes) {
	std::vector<int> factors;
	factors.clear();
	int i=0;
	int p = primes[0];
	while(p*p<=m) {
		if(m%p == 0) {
			factors.push_back(p);
			while(m%p==0) {
				m = m/p;
			}
		}
		i++;
		p = primes[i];

	}
	if(m!=1) {
			factors.push_back(m);
	}
	return factors;

}

int main(int argc, char const *argv[])
{
	int n=10000;
	int p[n];
	std::vector<int> primes = primeSieve(p, n);
	for(auto i: primes) {
		cout<<i<<endl;
	}
	return 0;
}

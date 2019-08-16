#include <iostream>
#include <unordered_map>
#define ll long long int
using namespace std;
int primes[1000005] = {0};
unordered_map<ll, ll> map;

void cubes(int n) {
	for (int i = 0; i < 1000005; i++) {
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
	map[1]=c;
	for (int i = 2; i < 1000005; i++) {
		if (primes[i] and i<1000000)
			map[i] = ++c;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cubes(1000000);
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(map.find(n)!=map.end()) {
			cout<<"Case "<<i<<": "<<map[n]<<"\n";
		} else {
			cout<<"Case "<<i<<": Not Cube Free\n";
		}
	}
	
	return 0;
}

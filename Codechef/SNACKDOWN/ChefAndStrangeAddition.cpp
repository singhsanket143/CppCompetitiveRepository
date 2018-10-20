#include <iostream>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--) {
		ll numa, numb, numc;
		cin>>numa>>numb>>numc;
		int arr[3];
		arr[0] = __builtin_popcount (numa);
		arr[1] = __builtin_popcount (numb);
		ll result = 0;
		for(int i=0;i<numc;i++) {
			if(__builtin_popcount(i) == arr[0] and __builtin_popcount(numc-i)==arr[1]) {
				result++;
			}
		}
		printf("%lld\n", result);
	}
	return 0;
}

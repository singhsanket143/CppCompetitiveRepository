#include <iostream>
#define ll long long int
using namespace std;
ll findTrailingZeros(ll n) {
	ll count = 0;
	for(int i=5;n/i>=1;i*=5) {
		count+=(n/i);
	}
	return count;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	cout<<findTrailingZeros(n);
	return 0;
}

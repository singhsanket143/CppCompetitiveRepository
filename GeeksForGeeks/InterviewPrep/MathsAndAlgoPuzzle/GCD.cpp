#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int a, b;
		cin>>a>>b;

	}
	return 0;
}

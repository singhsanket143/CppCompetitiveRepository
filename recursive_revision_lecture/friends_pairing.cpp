#include <iostream>
using namespace std;

int f(int n) {
	if(n == 1 or n == 2) return n;
	return f(n-1) + (n-1)*f(n-2);
}

int main() {
	cout<<f(5)<<"\n";
	return 0;
}

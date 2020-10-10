#include<iostream>
using namespace std;

int fib(int n) {
	// Base case
	if(n==0 or n==1) return n;
	return fib(n-1)+fib(n-2); // Self work and assumption
}

int main() {

	cout<<fib(8);
	return 0;
}

#include <iostream>
using namespace std;

intr fib(int n) {
	// Base case
	if(n==0 or n==1) return n;
	return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

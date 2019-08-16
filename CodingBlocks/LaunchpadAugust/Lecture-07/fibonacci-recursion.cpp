#include <iostream>
using namespace std;

int fib(int n) {
	// if(n==0 or n==1) {
	// 	return n;
	// }
	if(n==0) {
		return 0;
	}
	if(n==1) {
		return 1;
	}
	int result = fib(n-1) + fib(n-2);
	return result;
}

int main(int argc, char const *argv[])
{
	cout<<fib(5);
	return 0;
}

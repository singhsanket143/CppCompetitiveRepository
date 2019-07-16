#include <iostream>
using namespace std;

int fact(int n) {
	// base
	if(n==0) {
		return 1;
	}
	// Assumption
	int result = fact(n-1);
	// self work
	return n*result;
}

int main(int argc, char const *argv[])
{
	cout<<fact(5);
	return 0;
}

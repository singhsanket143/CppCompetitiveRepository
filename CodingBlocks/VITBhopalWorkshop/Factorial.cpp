#include <iostream>
using namespace std;

int fact(int n) {
	// Base case
	if(n==1 or n==0) return 1;
	// Recursive Assumption
	int result = fact(n-1);
	// Self work
	return n*result;
}

int main()
{
	cout<<fact(5);
	return 0;
}

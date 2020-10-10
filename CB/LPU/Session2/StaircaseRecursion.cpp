#include <iostream>
using namespace std;

int countStairPath(int n, int current, int k) {
	// Base case
	if(current > n) {
		return 0;
	}
	if(current == n) {
		return 1;
	}
	// Recursion
	int result = 0;
	for(int i=1;i<=k;i++) {
		result += countStairPath(n, current+i, k);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout<<countStairPath(7, 0, 3);
	return 0;
}

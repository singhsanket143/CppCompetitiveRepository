#include <iostream>
using namespace std;

int count setBits(int n) {
	int result = 0;
	while(n > 0) {
		n = n& (n-1);
		result++;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

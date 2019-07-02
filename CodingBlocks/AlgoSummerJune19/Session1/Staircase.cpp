#include <iostream>
using namespace std;

int staircase(int current, int n, int k) {
	if(current > n) {
		return 0;
	}
	if(current == n) {
		return 1;
	}
	int result = 0;
	for(int i=1;i<=k;i++) {
		result = result + staircase(current+i, n, k);
	}
	return result;
} 

int main(int argc, char const *argv[])
{
	/* code */
	cout<<staircase(0, 5, 3);
	return 0;
}

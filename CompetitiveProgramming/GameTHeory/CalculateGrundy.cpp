#include <iostream>
#include <unordered_set>
using namespace std;

int calculateMex(unordered_set<int> Set) {
	int mex = 0;
	while(Set.find(mex) != Set.end()) {
		mex++;
	}
	return mex;
}

int calculateGrundy(int n) {
	if(n == 0) {
		return 0;
	}
	unordered_set<int> Set;
	for(int i = 1; i <= n; i++) {
		Set.insert(calculateGrundy(n-i));
	}
	return calculateMex(Set);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	// create in heap memory
	int *ptr = new int;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;

	// 2 ways
	*ptr = 11;
	cout<<*ptr<<endl;

	// you can initialize with a default value

	float *fptr = new float(4.5);
	cout<<*fptr<<endl;

	delete fptr;
	return 0;
}
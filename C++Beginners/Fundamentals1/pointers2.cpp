#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	// lets make an int pointer
	int x = 200;
	int *ptr = &x; // address of int

	// let make a long long int pointer
	long long int y = 23456;
	long long int *lptr = &y; // address of long long int

	float ch = 5.6;
	float *c = &ch;


	// operator sizeof
	cout<<sizeof(ptr)<<" "<<sizeof(lptr)<<" "<<sizeof(c)<<endl;

	cout<<ptr<<endl;
	cout<<ptr+1<<endl; // 4 units added

	cout<<endl;

	cout<<lptr<<endl;
	cout<<lptr+1<<endl; // 8 unit
	cout<<--lptr<<endl;
	cout<<endl;
	cout<<c<<endl;
	cout<<c+1<<endl; // 4 units
	return 0;
}
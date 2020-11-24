#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	// Integer pointer -> they point to a memory address which stores integer

	int var = 200; // initialize a bucket and name it var	
	int *ptr = &var;
	cout<<ptr<<endl;
	cout<<&var<<endl;

	cout<<var<<endl; // 200
	cout<<*ptr<<endl; //200 -> dereference operator

	long l = 23000;
	long *lptr = &l;
	cout<<lptr<<endl;
	
	int **double_ptr = &ptr;
	cout<<double_ptr<<endl;
	cout<<*double_ptr<<endl;
	cout<<**double_ptr<<endl;

	*ptr = 30;
	cout<<*ptr<<endl;
	cout<<var<<endl;
	cout<<**double_ptr<<endl;

	**double_ptr = 12345;
	cout<<*ptr<<endl;
	cout<<var<<endl;
	cout<<**double_ptr<<endl;
	return 0;
}
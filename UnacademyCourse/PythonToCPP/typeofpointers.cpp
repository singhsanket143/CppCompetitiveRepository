#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int *p1 = NULL; // null pointer
	int *p2; // uninitialized pointer also called as wild pointer
	int x;
	cout<<p1<<" "<<p2<<" "<<x<<endl;



	// void pointer
	x = 10;
	long long int y = 20;

	int *px = &x; // address of x
	long long int *py = &y;

	cout<<x<<" "<<px<<" "<<px+1<<" "<<*px<<endl;
	cout<<y<<" "<<py<<" "<<py+1<<" "<<*py<<endl;

	void *ptr; // we cant dereference void ptr directly we have to typecast
	ptr = &x;
	cout<<ptr<<" "<<*((int *)ptr)<<endl;
	ptr = &y;
	cout<<ptr<<" "<<*((long long int *)ptr)<<endl;
	*((long long int *)ptr) = 88; // setting a value
	cout<<ptr<<" "<<*((long long int *)ptr)<<" "<<y<<endl;


	// concept of malloc;
	int *pm;
	void *v;
	v = malloc(sizeof(int)); // initialize in heap
	cout<<v<<endl;;
	pm = (int*)v;
	*pm = 10;
	free(v);
	return 0;
}
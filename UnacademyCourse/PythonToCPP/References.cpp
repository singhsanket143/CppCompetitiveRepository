#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	int &f = x; // f is a label of original bucket of x
	cout<<sizeof(x)<<" "<<sizeof(f)<<endl;
	cout<<x<<" "<<f<<endl;
	x = 12;
	cout<<x<<" "<<f<<endl;
	f = 15;
	cout<<x<<" "<<f<<endl;


	int y = 9;
	f = y;
	cout<<y<<" "<<f<<" "<<x<<endl;
	f = 18;
	cout<<y<<" "<<f<<" "<<x<<endl; // we cannot reassign a new bucket to a reference variable but reassignment is allowed in pointer

	// references cant be null; // pointers can be null
	// references need to be declared when defined;

	// int &f; -> not allowed
	// int *p; -> allowed
	return 0;
}
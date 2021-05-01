#include<iostream>
using namespace std;

int main()
{
	int x = 10; // this is a bucket which stores an int
	int* p1 = &x; // this is a bucket which stores address of int bucket
	int **p2 = &p1; // this is a bucket which stores address of a bucket which is storing the address of int bucket
	cout<<x<<" "<<p1<<" "<<p2<<endl;

	float y = 10.3;
	float *fptr = &y;

	cout<<sizeof(p1)<<" "<<sizeof(p2)<<" "<<sizeof(fptr)<<endl;

	int arr[5] = {12, 13, 14, 15, 16};
	cout<<(arr)<<endl;
	cout<<(arr+1)<<endl;
	cout<<(arr+2)<<endl;
	cout<<*(arr+1)<<endl;
	cout<<*(arr+2)<<endl;
	return 0;
}
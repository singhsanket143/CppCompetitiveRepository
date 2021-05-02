#include<iostream>
using namespace std;


void fun(int *z) {
	z[0] = 99;
	return;
}

void gun(int* &z) {
	z[1] = 88;
	return;
}

int main()
{
	int x;
	cin>>x;
	int *p = new int(x); //new always returns address of the bucket
	cout<<p<<" "<<*p<<endl;

	float *f = new float(9.5);
	cout<<*f<<endl;
	//void *v = new void(23); // error
	// a = [1,2,3,4], a stores the address of the base(0) index, a is an int pointer

	int **arr = new int*(&x); // pointer to a pointer

	int *a = new int[10]; // this initializes an array inside heap
	a[0] = 10;
	a[1] = 9;
	a[3] = 8;

	int rp[10]; // this initializes an array in stack frame

	delete f;
	delete [] a;

	int grid[10][19];
	int m, n;
	cin>>m>>n;
	int **arr2d = new int*[m]; // int*[10] means array of integer pointer// this creates the primary array in heap
	for(int i = 0; i < m; i++) {
		arr2d[i] = new int[n];
	}	

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>arr2d[i][j];
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout<<arr2d[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i = 0; i < m; i++) {
		delete [] arr2d[i];
	}
	// delete [] arr2d;


	// what if the memery is full in runtime and we try to do a dynamic memory alloc -> throws error bad_alloc
	// to avoid this we can use nothrow

	int *d = new(nothrow) int(9); // if we use nothrow and the memery is full it will not return bad_alloc error instead it will make it point to NULL
	if(!d) {
		cout<<"Mem alloc failed"<<endl;
	}
	cout<<*d<<endl;

	int *c = new int;
	cout<<*c<<endl;


	int *z = new int[*d](); // initialise array with all zeroes if we put () otherwise all random
	for(int i =0; i < 9; i++) {
		cout<<z[i]<<" ";
	}
	cout<<endl;
	fun(z);
	for(int i =0; i < 9; i++) {
		cout<<z[i]<<" ";
	}
	cout<<endl;
	gun(z);
	for(int i =0; i < 9; i++) {
		cout<<z[i]<<" ";
	}
	cout<<endl;
	int* &ref = z;


	int u = 10;
	int &uref = u;
	return 0;
}
#include<iostream>
using namespace std;

int main()
{
	/* code */

	// lets try to create a bucket of integer in heap


	int *ptr = new int(8); 
	cout<<*ptr<<endl;

	// lets try to create an array of integer in heap

	int *arr = new int[10];

	// init an array with all zeroes
	int *zeroes = new int[10]();


	for(int i = 0; i < 10; i++) {
		cout<<zeroes[i]<<" ";
	}
	cout<<endl;

	// create 2d array in heap
	int rows, cols;
	cin>>rows>>cols;
	int **grid = new int*[rows]; // this will just init the primary array
	for(int i = 0; i < rows; i++) {
		if(i == 0) {
			grid[i] = new int[1]();
		} else
			grid[i] = new int[cols]();
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < ((i == 0)? 1: cols); j++) {
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}

	// int *p;
	// for(int i = 0; i < 100000000; i++) {
	// 	p = new int[1000000];
	// }
	int *r = new int(nothrow)(10);
	if(!r) {
		cout<<"Memory not allocated"<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;


void swap(int x, int y) {
	// pass by value
	cout<<&x<<endl;
	int temp = x;
	x = y;
	y = temp;
	cout<<x<<" "<<y<<endl;
}

void swap1(int *x, int *y) { // because we get addresswe need to store them in ptr
	// pass by address
	int temp = *x; // dereferencing x
	*x = *y;
	*y = temp;
	cout<<*x<<" "<<*y<<endl;
}

void swap2(int &x, int &y) { // reference variable of original bucket
	// pass by reference
	cout<<&x<<endl;
	int temp = x;
	x = y;
	y = temp;
	cout<<x<<" "<<y<<endl;
}

int main()
{
	int x = 2;
	int y = 4;
	cout<<&x<<endl;
	cout<<x<<" "<<y<<endl;
	// swap(x, y); // we passed exact value
	// swap1(&x, &y); // we passed address
	swap2(x, y);
	cout<<x<<" "<<y<<endl;
	
	return 0;
}
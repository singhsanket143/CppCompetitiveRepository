#include <iostream>
#include <algorithm>
using namespace std;


void gun() {
	// comments
	// code
	int x = 10;

	return;
}
void fun() {
	// comments
	// code
	int x = 20;
	gun(); // new stack frame
	return;
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int arr[] = {1, 2, 3, 4, 5};

	for(int i=0;i<5;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	// How pointers can help in accessing the array

	for(int i = 0; i < 5; i++) {
		cout<<i<<" "<<(arr+i)<<" "<<*(arr+i)<<"\n";
	}
	int *ptr = arr; // arr has the base address
	for(int i = 0; i < 5; i++) {
		cout<<ptr<<" "<<*ptr<<endl;
		ptr++;
	}

	cout<<arr[2]<<endl; // value at 2nd index
	cout<<&arr[2]<<endl; // address of 2nd value

	fun();
	//gun(); // new stack frame
	return 0;
}
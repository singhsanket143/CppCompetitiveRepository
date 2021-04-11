#include<iostream>
using namespace std;

int main() {

	int arr[9];

	for(int i = 0; i < 9; i++) {
		cin>>arr[i];
	}


	arr[6] = 16;


	for(int i = 0; i < 9; i++) {
		cout<<arr[i]<<"\n";
	}
	return 0;
}
#include<iostream>
using namespace std;

int main() {

	int n; // n also represents no of bits
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int power_set_size = (1 << n) - 1;

	for(int i = 0; i <= power_set_size; i++) {
		cout<<"[";
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				cout<<arr[j]<<" ";
			}
		}
		cout<<"]\n";
	}
	return 0;
}
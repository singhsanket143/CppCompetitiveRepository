#include<iostream>
using namespace std;

int main() {

	int n;
	cin>>n;
	int arr[n];

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int a = 0,  b = 0, c = n-1;

	while(b <= c) {
		if(arr[b] == 0) {
			swap(arr[a], arr[b]);
			a++;
			b++;
		} else if(arr[b] == 1) {
			b++;
		} else {
			swap(arr[b], arr[c]);
			c--;
		}
	}

	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
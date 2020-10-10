#include <iostream>
using namespace std;

void dnf(int *arr, int n) {
	int s = 0, m = 0, e = n-1;
	while(m<=e) {
		if(arr[m] == 1) {
			m++;
		} else if(arr[m] == 2) {
			swap(arr[m], arr[e]);
			e--;
		} else {
			swap(arr[m], arr[s]);
			s++;
			m++;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	dnf(arr, n);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}

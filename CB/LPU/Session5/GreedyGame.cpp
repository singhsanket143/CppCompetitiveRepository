#include <iostream>
using namespace std;

int game(int *arr, int n, char start) {
	int even = 0;
	int odd = 0;
	for(int i=1;i<=n;i++) {
		if(i%2) {
			odd += arr[i-1];
		} else {
			even += arr[i-1];
		}
	}
	cout<<start<<" will win"<<endl;
	if(odd > even) {
		return odd;
	} else {
		return even;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char start;
	cin>>start;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<game(arr, n, start);
	return 0;
}

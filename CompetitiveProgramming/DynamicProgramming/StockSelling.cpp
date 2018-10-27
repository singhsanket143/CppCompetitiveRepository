#include <iostream>
using namespace std;

int stockSelling(int *arr, int si, int n, int k) {

	if(k > 0) {
		int retval1 = arr[si]+stockSelling(arr, si+1, n, k-1);
	}
	
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
	}
	return 0;
}

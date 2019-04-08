#include <iostream>
using namespace std;

void extraWalks(int *arr, int n, int k) {
	int result = 0;
	for(int i=1;i<n;i++) {
		int val = max(0, k-arr[i]-arr[i-1]);
		result += val;
		arr[i]+=val;
	}
	cout<<result<<endl;
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
} 

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	extraWalks(arr, n, k);
	return 0;
}

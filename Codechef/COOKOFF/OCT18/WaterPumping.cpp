#include <iostream>
#define inf 1e9
#define ll long long int
using namespace std;

int pump(int *arr, int si, int ei, int n) {
	int global_max = -inf;
	int c=-2;
	for(int j=si;j<=ei;j++) {
		if(arr[j]>global_max) {
			global_max = (arr[j]>global_max)?arr[j]:global_max;
			c=j;
		}
	}
	if( c==si or c==ei) {
		return 1;
	}
	int retval1 = pump(arr, si, c-1, n);
	int retval2 = pump(arr, c+1, ei, n);
	return min(retval1, retval2)+1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		cout<<pump(arr, 0, n-1, n)<<endl;
	}
	return 0;
}

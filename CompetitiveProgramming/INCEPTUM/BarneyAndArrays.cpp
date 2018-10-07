#include <iostream>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll ans = 0;
		for(int i=0;i<n;i++) {
			ans+=(n-1)*arr[i];
		}
		cout<<ans<<endl;
		delete [] arr;
	}
	return 0;
}

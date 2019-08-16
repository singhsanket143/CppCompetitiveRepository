#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr = new int[n+1];
		for(int i = 1; i <= n; i++) {
			cin>>arr[i];
		}
		int result = 0;
		for(int i = 1; i <= n; i++) {
			if(arr[i]%2!=0) {
				result ^= i;
			}
		}
		if(result == 0) {
			cout<<"Hanks Wins"<<"\n";
		} else {
			cout<<"Tom Wins"<<"\n";
		}
		delete[] arr;

	}
	return 0;
}

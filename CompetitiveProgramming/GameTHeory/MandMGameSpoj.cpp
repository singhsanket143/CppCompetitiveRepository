#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int count = 0;
		int *arr = new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			if(arr[i]==1) {
				count++;
			}
		}
		if(count == n) {
			if(n&1) {
				cout<<"Brother"<<"\n";
			} else {
				cout<<"John"<<"\n";
			}
		} else {
			int result = 0;
			for(int i = 0; i < n; i++) {
				result^=arr[i];
			}
			if(result==0) {
				cout<<"Brother"<<"\n";
			} else {
				cout<<"John"<<"\n";
			}
		}
		delete[] arr;
	}
	return 0;
}

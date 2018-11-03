#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
bool checkequal(ll *arr1, ll *arr2, int n) {
	for(int i=0;i<n;i++) {
		if(arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		ll arr1[n];
		ll arr2[m];
		int var1 = 0, var2 = 0, x;
		for(int i=0;i<n;i++) {
			cin>>x;
			if(x!=0) {
				arr1[var1++]=x;
			}
		}
		for(int i=0;i<m;i++) {
			cin>>x;
			if(x!=0) {
				arr2[var2++]=x;
			}
		}
		sort(arr1, arr1+var1);
		sort(arr2, arr2+var2);
		if(var1==var2) {
			if(checkequal(arr1, arr2, n)) {
				cout<<"Bob\n";
			} else {
				cout<<"Alice\n";
			}
		} else {
			cout<<"Alice\n";
		}
	}
	return 0;
}

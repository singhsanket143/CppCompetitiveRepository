#include<bits/stdc++.h>
using namespace std;
void file_i_o()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	file_i_o();
	// Write your code here....
	int n;
	cin>>n; // takes input of an integer from user
	int arr[n+1];
	for(int i = 1; i <= n; i++) {
		cin>>arr[i]; // takes input in the array
	}
	if(n == 1) {
		cout<<0;
		return 0;
	}
	if(n == 2) {
		cout<<abs(arr[1] - arr[2]);
		return 0;
	}
	int a = 0, b = abs(arr[1] - arr[2]);
	int c = -1;
	for(int i = 3; i <= n; i++) {
		c = min(a + abs(arr[i] - arr[i-2]), b + abs(arr[i] - arr[i-1]));
		a = b;
		b = c;
	}
	cout<<c;
	return 0;
}

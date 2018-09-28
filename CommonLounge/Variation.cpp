#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int n, k;
	cin>>n>>k;
	long long int arr[n];
	for(long long int i=0;i<n;i++) {
		cin>>arr[i];
	}
	sort(arr, arr+n);
	long long int result=0, i=0, j=0;
	while(i<n and j<n) {
		if(abs(arr[i]-arr[j])<k) {
			j++;
		} else {
			result+= n-j;
			i++;
		}
	}
	
	cout<<result;
	return 0;
}

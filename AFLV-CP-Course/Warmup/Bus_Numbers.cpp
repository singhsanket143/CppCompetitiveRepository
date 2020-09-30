// Problem Link - https://open.kattis.com/problems/busnumbers
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define DEBUG(x) 		cout << '>' << #x << ':' << x << endl;
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	file_i_o();
	ll n;
	scanf("%lld", &n);
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int i = 1, j = 0, count = 0;
	for(i = 1; i < n; i++) {
		if(arr[i] != arr[i-1] + 1) {
			if(i - j >= 3) {
				printf("%d-%d ", arr[j], arr[i - 1]);
			} else if (i - j == 2) {
				printf("%d %d ", arr[j], arr[i - 1]);
			} else {
				printf("%d ", arr[j]);
			}
			j = i;
		}
	}
	if(i - j >= 3) {
		printf("%d-%d ", arr[j], arr[i - 1]);
	} else if (i - j == 2) {
		printf("%d %d ", arr[j], arr[i - 1]);
	} else {
		printf("%d ", arr[j]);
	}
	return 0;
}

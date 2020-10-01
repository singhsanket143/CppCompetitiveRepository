// Problem Link - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B
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
	int n, k;
	cin>>n>>k;
	ll *arr = new ll[n];
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	ll lo = 1, hi = 1e15;
	ll result = 1;
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		int count_seg = 1;
		ll sum = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			if(sum + arr[i] > mid) {
				ans = max(ans, sum);
				sum = 0;
				count_seg++;
				if(count_seg > k) break;
			}
			sum += arr[i];
		}
		ans = max(ans, sum);
		if(count_seg > k) {
			lo = mid + 1;
		} else {
			if(count_seg == k) {
				result = ans;
			}
			hi = mid - 1;
		}
	}
	cout<<result;
	return 0;
}

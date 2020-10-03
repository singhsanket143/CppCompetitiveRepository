// Problem Link - https://www.codechef.com/problems/CHFIMPRS
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				map
#define ff 				first
#define ss 				second
#define loop(i,n) 		for(int i=0;i<(n);i++)
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
	int t;
	ump<int, int> mp;
	scanf("%d", &t);
	while(t--) {
		ll n, m, x;
		int c_odd = 0, c_even = 0;
		scanf("%lld %lld", &n, &m);
		loop(i, n) {
			loop(j, m) {
				scanf("%lld", &x);
				mp[x]++;
			}
		}
		
		for(auto x: mp) {
			if(mp[x.ff]&1) {
				c_odd++;
			} else {
				c_even++;
			}
		}
		int **arr = new int*[n];
		loop(i, n) {
			arr[i] = new int[m]();
		}
		bool notPossible = false;
		if(m&1) { // odd cols
			if(c_odd > n) {
				printf("-1\n");
				notPossible = true;
			}
			// setting the middle col
			int count = 0;
			for(auto x: mp) {
				if(mp[x.ff]&1) {
					arr[count][m/2] = x.ff;
					count++;
					mp[x.ff]--;
				}
				if(count >= n) break;
			}
			while(count < n) {
				auto it = mp.begin();
				if(mp[it->ff] == 0) {
					mp.erase(it->ff);
					continue;
				}
				arr[count][m/2] = it->ff;
				count++;
				mp[it->ff]--;
			}
		} else {
			if(c_odd > 0) {
				printf("-1\n");
				notPossible = true;
			}
		}
		for(auto x: mp) {
			if(mp[x.ff]&1 and !notPossible) {
				notPossible = true;
				break;
			}
		}
		if(!notPossible) {
			loop(i, n) {
				int left = 0, right = m-1;
				while(left < right) {
					auto it = mp.begin();
					if(mp[it->ff] == 0) {
						mp.erase(it->ff);
						continue;
					}
					if(it->ss%2==0) {
						arr[i][left] = it->ff;
						arr[i][right] = it->ff;
						mp[it->ff]-=2;
						left++;
						right--;
					}
				}
			}
			loop(i, n) {
				loop(j, m) {
					printf("%d ", arr[i][j]);
				}
				printf("\n");
			}
		}
		mp.clear();
	}
	return 0;
}

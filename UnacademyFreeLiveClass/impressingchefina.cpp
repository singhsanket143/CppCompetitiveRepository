#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

	int t;
	cin>>t;
	unordered_map<int, int> mp;
	while(t--) {
		int n, m;
		cin>>n>>m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				cin>>x;
				mp[x]++;
			}
		}

		int c_odd = 0, c_even = 0;
		for(auto x : mp) {
			if(x.second % 2 == 0) c_even++;
			else c_odd++;
		}
		int arr[n][m];
		bool notpossible = false;
		if(m % 2 != 0) {
			if(c_odd > n) {
				cout<<-1<<"\n";
				notpossible = true;
			} 
			int row = 0;
			for(auto x : mp) {
				if(x.second % 2 != 0) {
					arr[row][m/2] = x.first;
					row++;
					mp[x.first]--;
				}
				if(row >= n) break;
			}
			while(row < n) {
				auto it = mp.begin();
				if(mp[it->first] == 0) {
					mp.erase(it->first);
					continue;
				}
				arr[row][m/2] = it->first;
				row++;
				mp[it->first]--;
			}
		} else {
			if(c_odd > 0) {
				cout<<-1<<"\n";
				notpossible = true;
			}
		}


		if(notpossible == false) {
			for(int i = 0; i < n; i++) {
				int left = 0, right = m-1;
				while(left < right) {
					auto it = mp.begin();
					if(mp[it->first] == 0) {
						mp.erase(it->first);
						continue;
					}
					if(it->second%2 == 0) {
						arr[i][left] = it->first;
						arr[i][right] = it->first;
						left++;
						right--;
						mp[it->first]-=2;
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					cout<<arr[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
	}

	return 0;
}
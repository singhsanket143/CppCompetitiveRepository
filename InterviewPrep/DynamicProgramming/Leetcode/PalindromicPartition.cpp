#include <iostream>
#include <vector>
using namespace std;

int minPalindromicCut(string str) {
	int n = str.size();
	bool dp[n][n];
	int cut[n];
	for(int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	for(int l = 2; l <= n; l++) {
		for(int i = 0; i <= n-l; i++) {
			int j = i + l - 1;
			if(str[i] == str[j] and l == 2) {
				dp[i][j] = true;
			} else if (str[i] == str[j]) {
				dp[i][j] = dp[i+1][j-1];
			} else {
				dp[i][j] = false;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(dp[0][i] == true) { // string is palindrome from index 0 to i
			cut[i] = 0;
		} else {
			cut[i] = INT_MAX;
			for(int j = 0; j < i; j++) {
				if(dp[j+1][i]==true and 1 + cut[j] < cut[i]) {
					cut[i] = 1 + cut[j];
				}
			}
		}
	}
	return cut[n-1];

}

bool isPalindrome(string str) {
	int lo = 0, hi = str.size() - 1;
	while(lo <= hi) {
		if(str[lo] != str[hi]) {
			return false;
		}
		lo++;
		hi--;
	}
	return true;
}

void dfs(string s, int start, vector<string> &single, vector<vector<string> > &result) {
	if(s.size() <= start) {
		result.push_back(single);
		return;
	}
	for(int len = 1; start + len <= s.size(); len++) {
		string str = s.substr(start, len);
		if(isPalindrome(str)) {
			single.push_back(str);
			dfs(s, start+len, single, result);
			single.pop_back();
		}
	}
}

vector<vector<string> > partition(string s) {
	vector<string> single;
	vector<vector<string> > result;
	dfs(s, 0, single, result);
	return result;
}


int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<minPalindromicCut(str);
	return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> mp;
// bool wordBreak(string str) {
// 	if(str.size() == 0) return true;
// 	for(int i=1;i<=str.size();i++) {
// 		string prefix = str.substr(0, i);
// 		if(mp.find(prefix)!=mp.end() and wordBreak(str.substr(i))) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

bool wordBreak(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return true;
	}
	for(int i=1;i<=str.size();i++) {
		string prefix = str.substr(0, i);
		if(mp.find(prefix)!=mp.end() and wordBreak(str.substr(i), osf+prefix+" ")) {
			return true;
		}
	}
	return false;
}

bool wordBreakDP(string str, int *dp, string osf) {
	int n=str.size();
	if(str.size() == 0) {
		return true;
	}
	if(dp[n]==-1) {
		dp[n] = 0;
		for(int i=1;i<=str.size();i++) {
			string prefix = str.substr(0, i);
			if(mp.find(prefix)!=mp.end() and wordBreakDP(str.substr(i), dp, osf+prefix+" ")) {

				dp[n] = 1;
				return true;
			}
		}
	}
	return dp[n]==1;
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		mp[s] = true;
	}
	int dp[100];
	for(int i=0;i<100;i++) dp[i]=-1;
	cout<<wordBreakDP(str, dp, "");
	return 0;
}

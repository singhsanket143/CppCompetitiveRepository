#include <iostream>
using namespace std;
int lcsdp( string X, string Y, int m, int n )
{
	int L[m + 1][n + 1];
	int i, j;
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[m][n];
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		string s, t, p;
		cin >> s >> t >> p;
		int x = lcsdp(s, t, s.size(), t.size());
		if(x!=s.size()) {
			cout<<"NO\n";
			continue;
		}
		int *hashs = new int[26]();
		int *hasht = new int[26]();
		int *hashp = new int[26]();
		for (int i = 0; i < s.size(); i++) {
			hashs[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			hasht[t[i] - 'a']++;
		}
		for (int i = 0; i < p.size(); i++) {
			hashp[p[i] - 'a']++;
		}
		// for(int i=0;i<26;i++) {
		// 	cout<<hashs[i]<<",";
		// }
		// cout<<endl;
		// for(int i=0;i<26;i++) {
		// 	cout<<hasht[i]<<",";
		// }
		// cout<<endl;
		// for(int i=0;i<26;i++) {
		// 	cout<<hashp[i]<<",";
		// }
		// cout<<endl;
		bool flag = false;
		for (int i = 0; i < 26; i++) {
			if (hashs[i] + hashp[i] < hasht[i]) {
				cout << "NO\n";
				flag = true;
				break;
			}
		}
		if (flag == false) {
			cout << "YES\n";
		}
	}
	return 0;
}

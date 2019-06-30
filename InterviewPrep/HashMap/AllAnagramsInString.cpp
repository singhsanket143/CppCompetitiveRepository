#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(int *hashP, int *hashS) {
	for(int i=0;i<26;i++) {
		if(hashP[i] != hashS[i]) {
			return false;
		}
	}
	return true;
}

vector<int> findAllAnagrams(string s, string p) {
	int hashP[26] = {0};
	int hashS[26] = {0};
	for(int i=0;i<p.size();i++) {
		hashP[p[i]-'a']++;
		hashS[s[i]-'a']++;
	}
	vector<int> result;
	if(isAnagram(hashP, hashS)) result.push_back(0);
	for(int i=p.size();i<s.size();i++) {
			hashS[s[i-p.size()]-'a']--;
			hashS[s[i]-'a']++;
			if(isAnagram(hashP, hashS)) {
				result.push_back(i-p.size()+1);
			}
	}
	return result;

}


int main(int argc, char const *argv[])
{
	string s;
	string p;
	cin>>s>>p;
	vector<int> ans;
	ans=findAllAnagrams(s, p);
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}

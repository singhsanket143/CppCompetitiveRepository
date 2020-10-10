#include <iostream>
using namespace std;

bool isAnagram(int *hash1, int *hash2) {
	for(int i=0;i<26;i++) {
		if(hash1[i]!=hash2[i]) {
			return false;
		}
	}
	return true;
}

vector<int> allAnagram(string s1, string s2) {
	int hash1[26] = {0};
	int hash2[26] = {0};
	vector<int> result;
	if(s2.size() > s1.size()) {
		return result;
	}
	if(s1.size() < 1) return result;
	for(int i=0;i<s2.size();i++) {
		hash2[s2[i]-'a']++;
	}
	for(int i=0;i<s2.size();i++) {
		hash1[s1[i]-'a']++;
	}
	if(isAnagram(hash1, hash2)) {
		result.push_back(0);
	}



	for(int i=s2.size();i<s1.size();i++) {
		hash1[s1[i-s2.size()] - 'a']--;
		hash1[s1[i]-'a']++;
		if(isAnagram(hash1, hash2)) {
			result.push_back(i-s2.size()+1);
		}
	}
	return result;
}




int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	return 0;
}

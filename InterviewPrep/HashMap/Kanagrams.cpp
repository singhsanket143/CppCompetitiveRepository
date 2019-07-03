#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// ----------------------------------------------
bool areKAnagrams(string &s1, string &s2, int k)
{
	// write your code here
	if (s1.size() != s2.size()) {
		return false;
	}
	int mp1[26] = {0};
	int mp2[26] = {0};
	for (int i = 0; i < s1.size(); i++) {
		mp1[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		mp2[s2[i] - 'a']++;
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {

		count = count + abs(mp1[i] - mp2[i]);
	}
	return (count / 2) <= k;
}
// ----------------------------------------------

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int k = 0;
	cin >> k;

	if (areKAnagrams(s1, s2, k))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}
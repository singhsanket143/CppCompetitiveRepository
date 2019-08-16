#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(string str, int lo, int hi) {
	while(lo<=hi) {
		if(str[lo]!=str[hi])
			return false;
		lo++;
		hi--;
	}
	return true;
}
void partition(string str, int start, int n, vector<vector<string> > &allPartition, vector<string> &currPartition) {
	if(start>=n) {
		allPartition.push_back(currPartition);
		return;
	}
	for(int i=start;i<n;i++) {
		if(isPalindrome(str, start, i)) {
			currPartition.push_back(str.substr(start, i-start+1));
			partition(str, i+1, n, allPartition, currPartition);
			currPartition.pop_back();
		}
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<string> > allPartition;
    vector<string> currPartition;
    string A;
    cin>>A;
    partition(A, 0, A.size(), allPartition, currPartition);
	return 0;
}

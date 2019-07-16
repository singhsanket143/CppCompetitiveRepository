#include <iostream>
using namespace std;

void permutations(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	bool arr[26] = {0};

	for(int i=0;i<str.size();i++) {
		char ch = str[i];
		if(arr[ch-'a'] == false) {
			arr[ch-'a'] = true;
			string ros = str.substr(0, i)+str.substr(i+1);
			permutations(ros, osf+ch);
		}
		
	}
}

int main(int argc, char const *argv[])
{
	permutations("aaaa", "");
	return 0;
}

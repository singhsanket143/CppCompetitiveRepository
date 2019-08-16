#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int level = -1;
	int sum = 0;
	int k;
	cin>>k;
	for(int i=0;i<str.size();i++) {
		if(str[i]=='(') {
			level++;
		} else if(str[i]==')') {
			level--;
		} else {
			if(level == k) {
				sum+=(str[i]-'0');
			}
		}
	}
	cout<<sum;
	return 0;
}

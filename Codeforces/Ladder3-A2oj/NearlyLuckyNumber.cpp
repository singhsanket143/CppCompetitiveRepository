#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int count=0;
	for(int i=0;i<str.length();i++) {
		if(str[i]=='4' or str[i]=='7') count++;
	}
	if(count==4 or count ==7) cout<<"YES";
	else cout<<"NO";
	return 0;
}

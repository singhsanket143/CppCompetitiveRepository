#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c;
	cin>>a>>b>>c;
	map<int, int > mp;
	for(int i=0;i<a;i++) {
		int num;
		cin>>num;
		mp[num]++;
	}
	for(int i=0;i<b;i++) {
		int num;
		cin>>num;
		mp[num]++;
	}
	for(int i=0;i<c;i++) {
		int num;
		cin>>num;
		mp[num]++;
	}
	int result=0;
	for(auto itr = mp.begin(); itr != mp.end(); itr++) {
		if(itr->second >= 2) {
			result++;
		}
	}
	cout<<result<<endl;
	for(auto itr = mp.begin(); itr != mp.end(); itr++) {
		if(itr->second >= 2) {
			cout<<itr->first<<endl;
		}
	}
	return 0;
}

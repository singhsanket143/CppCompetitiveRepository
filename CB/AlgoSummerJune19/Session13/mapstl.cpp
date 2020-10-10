#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	// unordered_map<int, int> mp;
	// mp[10] = 12;
	// // mp.insert({11, 11});
	// // mp.insert({101, 11});
	// mp[11]= 13;
	// mp[10] += 2;
	// mp[99] = 100;
	// mp[10] = 11;
	// for(auto it = mp.begin();it!=mp.end();it++) {
	// 	cout<<(*it).first<<" , "<<(*it).second<<endl;;
	// }
	// cout<<(mp.find(1009)!=mp.end());
	// mp.erase(10);
	// mp.clear();
	map<int, int> mp;
	mp[10] = 12;
	// mp.insert({11, 11});
	// mp.insert({101, 11});
	mp[11]= 13;
	mp[10] += 2;
	mp[99] = 100;
	mp[10] = 11;
	for(auto it = mp.begin();it!=mp.end();it++) {
		cout<<(*it).first<<" , "<<(*it).second<<endl;;
	}
	cout<<(mp.find(1009)!=mp.end());
	// mp.erase(10);
	// mp.clear();
	return 0;
}

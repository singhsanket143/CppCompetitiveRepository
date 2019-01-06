#include <iostream>
#include<map>
using namespace std;
int main(int argc, char const *argv[])
{
	map<int, int>mp;
	mp.insert({10, 1});
	mp.insert({15, 2});
	mp.insert({2, 3});
	mp.insert({-1, 4});
	
	
	for(auto it = mp.begin(); it!=mp.end();it++) {
		cout<<(*it).first<<"->"<<(*it).second<<endl;
	}
	return 0;
}

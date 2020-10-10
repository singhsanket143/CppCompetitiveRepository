#include <iostream>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	unordered_map<string, int>mp;
	mp.insert({"coding", 1});
	mp.insert({"blocks", 2});
	mp.insert({"algo", 3});
	mp.insert({"c++", 4});
	
	mp.erase("algo");
	for(unordered_map<string, int>::iterator it = mp.begin(); it!=mp.end();it++) {
		cout<<(*it).first<<"->"<<(*it).second<<endl;
	}
	return 0;
}

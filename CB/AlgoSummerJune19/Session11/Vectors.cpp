#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	for(int i=0;i<10;i++) {
		v.push_back(i);
	}
	v.pop_back();
	v.pop_back();
	for(auto it = v.begin();it!=v.end();it++) {
		cout<<(*it)<<endl;
	}
	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<endl;
	}
	return 0;
}

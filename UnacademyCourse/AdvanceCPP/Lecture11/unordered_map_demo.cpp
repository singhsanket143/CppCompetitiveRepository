#include<iostream>
#include <unordered_map>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

struct hash_pair {
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const {
		auto h1 = hash<T1>()(p.first);
		auto h2 = hash<T2>()(p.second);
		return h1^h2;
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	unordered_map<char, int> mp;
	pair<int, int> p1;

	cout<<sizeof(mp)<<endl;
	mp['a'] = 65;
	mp['b'] = 66;
	mp['c'] = 67;
	mp.insert(pair<char, int>('z', 100));
	mp.insert({'l', 12});
	mp.emplace('m', 33);
	for(auto &p : mp) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	mp.erase('c');
	auto x = mp.begin();
	x++;
	mp.erase(x);
	unordered_map<char,int>::iterator it;
	for(it = mp.begin(); it!= mp.end(); it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}

	// auto lb = mp.lower_bound('b');
	// cout<<lb->second<<endl;
	cout<<mp.count('a')<<endl;
	if(mp.find('c') == mp.end()) {
		// nothing found
	} else {
		// found
	}

	unordered_map<pair<int, int>, int, hash_pair> mp1;
	cout<<"**"<<endl;
	unordered_map<char,int>::iterator it1;
	for(it1 = mp.begin(); it1!= mp.end(); it1++) {
		if(it1->first == 'a') {
			mp.erase(it1);
		}
	}
	for(auto &p : mp) {
		if(p.first == 'm') {
			mp.erase(p.first);
		}
	}
	for(auto &p : mp) {
		cout<<p.first<<" "<<p.second<<endl;
	}


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

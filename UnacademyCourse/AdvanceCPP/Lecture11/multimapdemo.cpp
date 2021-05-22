#include<iostream>
#include <map>
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	multimap<char, int> mp;
	pair<int, int> p1;

	cout<<sizeof(mp)<<endl;
	
	mp.insert(pair<char, int>('z', 100));
	mp.insert({'l', 12});
	mp.insert({'l', 13});
	mp.insert({'l', 14});
	mp.insert({'l', 13});
	mp.emplace('m', 33);
	for(auto &p : mp) {
		cout<<p.first<<" "<<p.second<<endl;
	}

	auto it = mp.find('l');
	cout<<it->second<<endl;
	// mp.erase('c');
	// auto x = mp.begin();
	// x++;
	// mp.erase(x);
	// multimap<char,int>::iterator it;
	// for(it = mp.begin(); it!= mp.end(); it++) {
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }

	// auto lb = mp.lower_bound('b');
	// cout<<lb->second<<endl;
	// cout<<mp.count('a')<<endl;
	// if(mp.find('c') == mp.end()) {
	// 	// nothing found
	// } else {
	// 	// found
	// }

	// multimap<pair<int, int>, int> mp1;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

#include<bits/stdc++.h>
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
	list<int> first;
	first.push_back(10);
	first.push_front(20);
	first.emplace_back(33);

	for(list<int>::iterator it = first.begin(); it != first.end();) {
		cout<<*it<<" ";
		it++;
	}

	cout<<endl;

	for(auto it = first.begin(); it != first.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	for(auto el : first) {
		cout<<el<<" ";
	}
	cout<<endl;

	list<int> second(first);

	for(auto el : second) {
		cout<<el<<" ";
	}
	cout<<endl;

	list<int> third(4, 100);
	for(auto el: third) {
		cout<<el<<" ";
	}
	cout<<endl;

	list<int> fourth(third.begin(), third.end());
	for(auto el: fourth) {
		cout<<el<<" ";
	}
	cout<<endl;

	fourth.merge(first);
	for(auto it = fourth.begin(); it != fourth.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
	fourth.sort();
	for(auto el: fourth) {
		cout<<el<<" ";
	}
	cout<<endl;

	// adjacency list
	int v = 5;
	vector<list<int> > graph(v);



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

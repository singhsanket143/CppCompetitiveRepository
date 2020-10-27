// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	file_i_o();
	// stack<int> st; // new stack - LIFO
	// st.push(10);
	// st.push(20);
	// st.push(30);
	// st.push(40);
	// st.emplace(50);
	// cout<<st.size()<<endl;
	// while(not st.empty()) {
	// 	cout<<st.top()<<endl;
	// 	st.pop();
	// }

	// // st.emplace() == st.push()

	// queue<int> qu; // new queue - FIFO
	// qu.push(10);
	// qu.push(20);
	// qu.push(30);
	// qu.push(40);
	// qu.emplace(50);
	// cout<<qu.size()<<endl;
	// while(not qu.empty()) {
	// 	cout<<qu.front()<<endl;
	// 	qu.pop();
	// }
	// int x = 0;
	// bitset<32> b1;
	// b1[2] = 1;
	// b1[31] = 1; // array like representation
	// bitset<32> b2(8);
	// string str = "1011";
	// bitset<100> b3(str);
	// log(b1, b2, b3);
	//log(b2&b3, b2|b3, b2^b3, ~b3, b2<<5, b2==b3);
	// b3.set(1);
	//log(b3.count(), b3.flip(), !b3.none());

	list<int> li;
	loop(i, 0, 5) {
		li.emplace_back(i);
	}
	cout<<li[3]<<endl;
	// loop(i, 10, 15) {
	// 	li.push_front(i);
	// }
	// li.pop_front();
	// li.pop_back();

	// for(int el: li) {
	// 	cout<<el<<" ";
	// }
	// cout<<endl;
	// cout<<li.front()<<" "<<li.back()<<endl;
	// li.reverse();
	// li.sort();
	// list<int>::iterator it = li.begin();
	// advance(it, 3);
	// li.insert(it, 33);
	// for(int el: li) {
	// 	cout<<el<<" ";
	// }
	// cout<<endl;
	// for(auto x = li.begin(); x!=li.end(); x++) {
	// 	cout<<*x<<" ";
	// }

	// double ended queue
	deque<int> qu;
	loop(i, 0, 5) {
		qu.emplace_back(i);
	}
	cout<<qu[1];
	return 0;
}

// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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

class employee {
private:
	string name;
	long id;
public:
	employee() {
		cout<<"Called employee constructor\n";
	}
	void get_data() const {
		cout<<"Name: "<<name<<endl;
		cout<<"ID: "<<id<<endl;
	}
	void set_data() {
		cout<<"Enter a name"; cin>>name;
		cout<<"Enter a id"; cin>>id;
	}
};

class student {
private:
	string schoolname;
	string degree;
public:
	student() {
		cout<<"Called student constructor\n";
	}
	void get_data() const {
		cout<<"schoolname: "<<schoolname<<endl;
		cout<<"degree: "<<degree<<endl;
	}
	void set_data() {
		cout<<"Enter a schoolname"; cin>>schoolname;
		cout<<"Enter a degree"; cin>>degree;
	}
};


class Manager : private student, private employee {
private:
	string title;
	double salary;
public:
	Manager() {
		cout<<"Called Manager constructor\n";
	}
	void get_data() const {
		employee::get_data();
		cout<<"title: "<<title<<endl;
		cout<<"salary: "<<salary<<endl;
		student::get_data();
	}
	void set_data() {
		employee::set_data();
		cout<<"Enter a title"; cin>>title;
		cout<<"Enter a salary"; cin>>salary;
		student::set_data();
	}
};

class SDE1 : public employee {

};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Manager m1;
	m1.set_data();

	m1.get_data();

	SDE1 s1;
	s1.set_data();
	s1.get_data();

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define vi              vector<ll>
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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";	


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

	// string str = "codechef";
	// cout<<str<<endl;
	// string str1("sanket");
	// cout<<str1<<endl;
	// string str2(5, 'q');
	// cout<<str2<<endl;
	// for(int i = 0; i < 5; i++) {
	// 	str.push_back('a');
	// }
	// // pop_back
	// cout<<str<<endl;

	// cout<<str.size()<<endl;
	// cout<<str.capacity()<<endl;
	// cout<<str[3]<<endl;
	// cout<<str.at(2)<<endl;

	// str.swap(str1);
	// cout<<str<<endl;
	// cout<<str1<<endl;


	// string s;
	// while(getline(cin, s))
	// 	cout<<s<<endl;
	// int n;
	// while(cin>>n) {
	// 	cout<<n<<endl;
	// }
	// int n;
	// while(scanf("%d", &n) != EOF) {
	// 	cout<<n<<endl;
	// }

	// String tokenizer
	string str;
	cin>>str;
	 // sanket-singh
	// strtok
	// char *token = strtok(&str[0], "-");
	// while(token != NULL) {
	// 	cout<<token<<"\n";
	// 	token = strtok(NULL, "-");
	// }


	// better and more modern way
	istringstream var(str);
	string token;
	while(getline(var, token, '-')) {
		cout<<token<<endl;
	}

	string a = "abc";
	string b = "abc";
	cout<< (a == b)<<endl;

	return 0;

	// a - true
	// b - false
	// c - error
	// d = None
}

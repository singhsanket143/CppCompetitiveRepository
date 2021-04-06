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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<"\n";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string &str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


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

vs typosquats1(vs companyDomains, vs newDomains) {
	unordered_map<string, unordered_set<string> > mp;
	for(string &str: companyDomains) {
		vector<string> temp = tokenizer(str, '.');
		mp[temp[0]].insert(temp[1]);
	}	
	vector<string> result;
	for(string &str: newDomains) {
		vector<string> temp = tokenizer(str, '.');
		if(mp.find(temp[0]) == mp.end()) continue;
		if(mp[temp[0]].find(temp[1]) == mp[temp[0]].end()) {
			result.push_back(temp[0] + "." + temp[1]);
		}
	}
	return result;
}

int minOperations(string A, string B) {
    if(A.size() != B.size()) 
        return -1; 
      
    int i, j, res = 0; 
    int count[256]; 
      
    for(i = 0; i < A.size(); i++) 
    { 
        count[A[i]]++; 
        count[B[i]]--; 
    } 
      
    for(i = 0; i < 256; i++) 
        if(count[i] != 0) 
            return -1; 
      
    i = A.size() - 1; 
    j = B.size() - 1; 

    while(i >= 0) 
    { 
        if(A[i] != B[i]) 
            res++; 
        else
            j--; 
        i--;          
    } 
    return res;      
} 

vs typosquats3a(vs companyDomains, vs newDomains) {
	unordered_set<string> mp;
	for(int i=0;i<companyDomains.size();i++) {
		vector<string> temp = tokenizer(companyDomains[i], '.');
		mp.insert(temp[0]);
	}
	vector<string> result;
	for(string &str: newDomains) {
		vector<string> temp = tokenizer(str, '.');
		if(mp.find(temp[0]) != mp.end()) {
			result.push_back(str);
			continue;
		}
		for(int i = 0; i < str.size() - 1; i++) {
			swap(str[i], str[i+1]);
			vector<string> temp = tokenizer(str, '.');
			if(mp.find(temp[0]) != mp.end()) {
				swap(str[i], str[i+1]);
				result.push_back(str);
				break;
			}
			swap(str[i], str[i+1]);
		}
	}
	return result;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	cin>>n;
	vs companyDomains(n);
	loop(i, 0, n-1) {
		cin>>companyDomains[i];
	}
	int m;
	cin>>m;
	vs newDomains(m);
	loop(i, 0, m-1) {
		cin>>newDomains[i];
	}
	vs result = typosquats3a(companyDomains, newDomains);
	logarr(result, 0, result.size() - 1);
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

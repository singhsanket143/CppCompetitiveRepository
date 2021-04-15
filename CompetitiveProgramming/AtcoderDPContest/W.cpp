// Problem Link - https://atcoder.jp/contests/dp/tasks/dp_w
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

class segtree
{
    ll *tree;
    ll *upd;
    int n;
public:
    segtree(int n)
    {
        this->n = n;
        tree = new ll[4*n];
        upd = new ll[4*n];
        for(int i=0;i<4*n;i++)
            tree[i] = upd[i] = 0;
    }
    void push(int node)
    {
        tree[2*node+1] += upd[node];
        tree[2*node+2] += upd[node];
        upd[2*node+1] += upd[node];
        upd[2*node+2] += upd[node];
        upd[node] = 0;
    }
    void update(int li, int ri, ll val)
    {
        lazyProp(0,0,n-1,li,ri,val);
    }
    void lazyProp(int node, int ln, int rn, int li, int ri, ll val)
    {
        if(ri < ln || rn < li)
            return;
        if(li <= ln && rn <= ri)
        {
            tree[node] += val;
            upd[node] += val;
            return;
        }
        int mid = (ln + rn)/2;
        push(node);
        lazyProp(2*node + 1, ln, mid, li, ri, val);
        lazyProp(2*node + 2, mid + 1, rn, li, ri, val);
        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }
    ll query(int li, int ri, int node = 0, int ln = 0, int rn = - 1)
    {
        rn = (rn == -1)?n-1:rn;
        if(ri < ln || rn < li)
            return -(inf);
        if(li <= ln && rn <= ri)
        {
            return tree[node];
        }
        int mid = (ln+rn)/2;
        push(node);
        ll v1 = query(li, ri, 2*node+1, ln, mid);
        ll v2 = query(li, ri, 2*node+2, mid+1, rn);
        return max(v1, v2);
    }
};


struct interval {
	ll score;
	int o;
	int c;
};


ll intervals(vector<interval> &v, int n) {
	segtree dp(n);
	vector<int> end_[n];
	for(int i = 0; i < v.size(); i++) {
		end_[v[i].c].pb(i);
	}
	for(int i: end_[0]) {
		dp.update(v[i].o, v[i].c, v[i].score);
	}

	for(int i = 1; i <n; i++) {
		ll maximum = max(dp.query(0, i-1), 0LL);
		dp.update(i, i, maximum);
		for(int j: end_[i]) {
			dp.update(v[j].o, v[j].c, v[j].score);
		}
	}
	return max(dp.query(0, n-1), 0LL);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....


	int n, m;
	cin>>n>>m;
	vector<interval> v(m);
	loop(i, 0, m-1) {
		cin>>v[i].o>>v[i].c>>v[i].score;
		v[i].o--;
		v[i].c--;
	}
	cout<<intervals(v, n);


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

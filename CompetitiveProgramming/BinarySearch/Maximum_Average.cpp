// Problem Link - https://codeforces.com/edu/course/2/lesson/6/4/practice
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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";	
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
	int n, d;
	cin>>n>>d;
	vector<ld> arr(n);
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	ld fullavg = accumulate(arr.begin(), arr.end(), 0.0) / (1.0*n);
	setprecision(10);
	vector<ld> pre(n);
	pre[0] = arr[0];
	loop(i, 1, n-1) {
		pre[i] += pre[i-1] + arr[i];
	}
	ld lo = 0, hi = 10000000;
	ld result = -1 * numeric_limits<ld>::max();
	int lidx = -1, ridx = -1;
	while(1e-9 <= hi - lo) {
		ld mid = lo + (hi - lo) / 2;
		// log(mid);
		vector<ld> temp(arr.begin(), arr.end());
		loop(i, 0, n-1) {
			temp[i] -= mid;
		}
		// logarr(temp, 0, n-1);
		// cout<<endl;
		loop(i, 1, n-1) {
			temp[i] += temp[i-1];
		}
		ll ri = d-1;
		vi min_(n);
		min_[0] = 0;
		loop(i, 1, n-1) {
			if(temp[min_[i-1]] < temp[i]) {
				min_[i] = min_[i-1];
			} else {
				min_[i] = i;
			}
		}
		// logarr(temp, 0, n-1);
		// cout<<endl;
		// logarr(min_, 0, n-1);
		// cout<<endl;
		bool flag = false;
		loop(i, ri, n-1) {
			if(i-d < 0) {
				if(temp[i] >= 0) {
					ld avg = pre[i]/(i+1);
					//log(avg);
					if(avg >= result) {
						flag = true;
						result = avg;
						
						lidx = -1;
						ridx = i;
						//log(result, avg, lidx, ridx);
					}
				}
				continue;
			}
			if( 1e-8 <= temp[i] - temp[min_[i-d]] ) {
				ld avg = (pre[i] - pre[min_[i-d]]) / (i - min_[i-d]);
				//log(avg, i, min_[i-d]);
				if(avg >= result) {
					flag = true;
					result = avg;
					
					lidx = min_[i-d];
					ridx = i;
					//log(result, avg, lidx, ridx);
				}
				break;
			}
		}

		if(flag) {
			lo = mid;
		} else {
			hi = mid;
		} 
	}

	if(fullavg >= result) {
		cout<<1<<" "<<n;

	} else {

		cout<<(lidx+2)<<" "<<(ridx+1);

	}
	return 0;
}

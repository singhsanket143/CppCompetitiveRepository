#include<bits/stdc++.h>
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
long double findDist(int x, int y) {
	return sqrtl(x*x + y*y);
}

// vector<vector<int>> findRestraunts(vector<vector<int>> allocations, int numRestraunts) {
// 	priority_queue<pair<long double, pair<int, int>>> pq;
// 	for(int i = 0; i < allocations.size(); i++) {
// 		long double distance = findDist(allocations[i][0], allocations[i][1]);
// 		if(pq.size() == numRestraunts) {
// 			if(distance < pq.top().first) {
// 				pq.pop();
// 				pq.push(make_pair(distance, make_pair(allocations[i][0], allocations[i][1])));
// 			}
// 		} else {
// 			pq.push(make_pair(distance, make_pair(allocations[i][0], allocations[i][1])));
// 		}
// 	}
// 	vector<vector<int>> result;
// 	while(not pq.empty()) {
// 		vector<int> coordinate(2);
// 		coordinate[0] = pq.top().second.first;
// 		coordinate[1] = pq.top().second.second;
// 		pq.pop();
// 		result.push_back(coordinate);
// 	}
// 	return result;

// }

bool cmp(vector<int> x, vector<int> y) {
	return x[1] < y[1];
}

vector<vector<int>> applicationPairs(int deviceCapacity, vector<vector<int>> foreGroundAppList, vector<vector<int>> backGroundAppList) {
	
	priority_queue<pair<int, pair<int, int>>>pq;
	sort(foreGroundAppList.begin(), foreGroundAppList.end(), cmp);
	sort(backGroundAppList.begin(), backGroundAppList.end(), cmp);
	set<pair<int, int>> p;
	int i = foreGroundAppList.size() - 1;
	int j = backGroundAppList.size() - 1;

	int reqdSum = -1;
	int sum = foreGroundAppList[i][1] + backGroundAppList[j][1];
	vector<vector<int>> result;
	pq.push(make_pair(sum, make_pair(i, j)));
	while(!pq.empty()) {
		sum = pq.top().first;
		if(sum <= deviceCapacity) {
			if(sum < reqdSum) break;
			reqdSum = sum;
		}
		if(reqdSum != -1) {
			vector<int> x(2);
			x[0] = foreGroundAppList[pq.top().second.first][0];
			x[1] = backGroundAppList[pq.top().second.second][0];
			result.push_back(x);
		}
		pair<int, pair<int, int>> temp = pq.top();
		if(!pq.empty()) {
			pq.pop();
		}
		if(temp.second.first-1>=0 and p.find(make_pair(temp.second.first- 1, temp.second.second)) == p.end()) {
			pq.push(make_pair(foreGroundAppList[temp.second.first - 1][1]+backGroundAppList[temp.second.second][1], make_pair(temp.second.first - 1, temp.second.second)));
			p.insert(make_pair(temp.second.first - 1, temp.second.second));
		}
		if(temp.second.second-1>=0 and p.find(make_pair(temp.second.first, temp.second.second - 1)) == p.end()) {
			pq.push(make_pair(foreGroundAppList[temp.second.first][1]+backGroundAppList[temp.second.second - 1][1], make_pair(temp.second.first, temp.second.second - 1)));
			p.insert(make_pair(temp.second.first, temp.second.second - 1));

		}
	}
	

	
	return result;

}


int main(int argc, char const *argv[]) {
	file_i_o();
	// int n, temp, deviceCapacity;
	// cin>>n>>temp;
	// vector<vector<int>> f;
	// vector<vector<int>> b;
	// while(n--) {
	// 	vector<int> coordinate(2);
	// 	cin>>coordinate[0];
	// 	cin>>coordinate[1];
	// 	f.push_back(coordinate);
	// }
	// while(temp--) {
	// 	vector<int> coordinate(2);
	// 	cin>>coordinate[0];
	// 	cin>>coordinate[1];
	// 	b.push_back(coordinate);
	// }
	// cin>>deviceCapacity;
	// vector<vector<int>> result = applicationPairs(deviceCapacity, f, b);
	// for(int i = 0; i < result.size(); i++) {
	// 	cout<<result[i][0]<<" "<<result[i][1]<<endl;
	// }
	// return 0;
	bitset<10> a[20];
	cout<<a[0];
}

/* In this problem we are asked to find the K nearest coordinates with respect to x=0, y=0 coordinated.
The problem falls in the category of Order Statistics problem in which we have to find K elements 
by any order. 
*/

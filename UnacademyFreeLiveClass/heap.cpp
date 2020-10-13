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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";cout<<endl;	
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
// Max Heap
void upheapify(vector<int> &heap, int idx) {
	if (idx == 0) return;
	int pi = (idx - 1)/2;
	if(heap[pi] < heap[idx]) {
		int temp = heap[pi];
		heap[pi] = heap[idx];
		heap[idx] = temp;
		upheapify(heap, pi);
	} else {
		return;
	}
}

void downheapify(vector<int> &heap, int i) {
	int li = 2*i+1;
	int ri = 2*i+2;
	if(li >= heap.size() and ri >= heap.size()) return;
	int largestIdx = i;
	if(li < heap.size() and heap[li] > heap[largestIdx]) {
		largestIdx = li;
	} 
	if(ri < heap.size() and heap[ri] > heap[largestIdx]) {
		largestIdx = ri;
	} 
	if(largestIdx == i) return;
	swap(heap[i], heap[largestIdx]);
	downheapify(heap, largestIdx);
}

void deletePeek(vector<int> &heap) {
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downheapify(heap, 0);
}

void buildHeapOptimised(vector<int> &heap) {
	for(int i = heap.size() - 1; i >= 0; i--) {
		downheapify(heap, i);
	}
}

int main(int argc, char const *argv[]) {
	file_i_o();
	// vector<int> heap;
	// int n;
	// cin>>n;
	// loop(i, 0, n-1) {
	// 	int x;
	// 	cin>>x;
	// 	heap.pb(x);
	// 	upheapify(heap, i);
	// }
	// logarr(heap, 0, heap.size() - 1);
	// deletePeek(heap);
	// logarr(heap, 0, heap.size() - 1);
	// priority_queue<int, vector<int>, greater<int> > pq; // max heap
	// pq.push(10);
	// pq.push(20);
	// pq.push(30);
	// pq.push(40);
	// pq.push(50);
	// pq.push(60);
	// while(!pq.empty()) {
	// 	cout<<pq.top()<<" ";
	// 	pq.pop();
	// }
	// cout<<endl;
	vector<int> arr {2, 3, 10, -1, 5, 4, 19, 7, 0, 12};
	logarr(arr, 0, arr.size() - 1);
	buildHeapOptimised(arr);
	logarr(arr, 0, arr.size() - 1);

	return 0;
}

#include <iostream>
#define ll long long int
using namespace std;
class Custom{
public:
	ll sqval;
	ll val;
	ll lazy;
	int type;
};


void build(int *arr, Custom **seg, int n, int low, int high, int node) {
	if(low > high) return;
	if(low == high) {
		seg[node] = new Custom();
		seg[node]->sqval = arr[low]*arr[low];
		seg[node]->val = arr[low];
		seg[node]->type = 0;
		seg[node]->lazy = 0;
		return;
	}
	seg[node] = new Custom();
	seg[node]->lazy = 0;
	seg[node]->type = 0;
	int mid = (low+high)/2;
	build(arr, seg, n, low, mid, 2*node);
	build(arr, seg, n, mid+1, high, 2*node+1);
	seg[node]->sqval = seg[2*node]->sqval + seg[2*node+1]->sqval;
	seg[node]->val = seg[2*node]->val + seg[2*node+1]->val;
}

void update(Custom **seg, int low, int high, int L, int R, int inc, int type, int node) {
	
	if(seg[node]->type != 0) {
		if(seg[node]->type == 1) {
			seg[node]->sqval += (2*seg[node]->lazy*seg[node]->val + (high-low+1)*seg[node]->lazy*seg[node]->lazy);
			seg[node]->val += (high-low+1)*seg[node]->lazy;
		} else if(seg[node]->type == 2) {
			seg[node]->sqval = (high-low+1)*seg[node]->lazy*seg[node]->lazy;
			seg[node]->val = (high-low+1)*seg[node]->lazy;
		}
		if(low!=high) {
			seg[2*node]->type = seg[node]->type;
			seg[2*node+1]->type = seg[node]->type;
			seg[2*node]->lazy = seg[node]->lazy;
			seg[2*node+1]->lazy = seg[node]->lazy;
		}
		seg[node]->lazy = 0;
		seg[node]->type = 0;
	}
	if(low > high or low > R or high < L) return;
	if(low >= L and high <= R) {
		if(type == 1) {
			seg[node]->sqval += 2*inc*seg[node]->val + (high-low+1)*inc*inc;
			seg[node]->val += (high-low+1)*inc;
		} else if(type == 2) {
			seg[node]->sqval = (high-low+1)*inc*inc;
			seg[node]->val = (high-low+1)*inc;
		}
		if(low != high) {
			seg[2*node]->type = type;
			seg[2*node+1]->type = type;
			seg[2*node]->lazy = inc;
			seg[2*node+1]->lazy = inc;
		}
		return;
	}
	int mid = (low+high)/2;
	update(seg, low, mid, L, R, inc, type, 2*node);
	update(seg, mid+1, high, L, R, inc, type, 2*node+1);
	seg[node]->sqval = seg[2*node]->sqval + seg[2*node+1]->sqval;
	seg[node]->val = seg[2*node]->val + seg[2*node+1]->val;
}

ll query(Custom **seg, int low, int high, int L, int R, int node) {
	if(low > high or low > R or high < L) return 0;
	if(seg[node]->type != 0) {
		if(seg[node]->type == 1) {
			seg[node]->sqval += 2*seg[node]->lazy*seg[node]->val + (high-low+1)*seg[node]->lazy*seg[node]->lazy;
			seg[node]->val += (high-low+1)*seg[node]->lazy;
		} else if(seg[node]->type == 2) {
			seg[node]->sqval = (high-low+1)*seg[node]->lazy*seg[node]->lazy;
			seg[node]->val = (high-low+1)*seg[node]->lazy;
		}
		if(low!=high) {
			seg[2*node]->type = seg[node]->type;
			seg[2*node+1]->type = seg[node]->type;
			seg[2*node]->lazy = seg[node]->lazy;
			seg[2*node+1]->lazy = seg[node]->lazy;
		}
		seg[node]->lazy = 0;
		seg[node]->type = 0;
	}
	if(low >= L and high <= R) {
		return seg[node]->sqval;
	}	
	int mid = (low+high)/2;
	ll left = query(seg, low, mid, L, R, 2*node);
	ll right = query(seg, mid+1, high, L, R, 2*node+1);
	return left+right;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
		int n, q;
		cin>>n>>q;
		int *arr = new int[n]();
		for(int i =0;i < n;i++) {
			cin>>arr[i];
		}
		Custom** seg = new Custom*[4*n];
		build(arr, seg, n, 0, n-1, 1);
		cout<<"Case "<<i+1<<":"<<endl;
		while(q--) {
			int type;
			cin>>type;
			if(type == 2) {
				int l, r;
				cin>>l>>r;
				cout<<query(seg, 0, n-1, l-1, r-1, 1)<<endl;
			} else if(type == 1) {
				int l, r, inc;
				cin>>l>>r>>inc;
				update(seg, 0, n-1, l-1, r-1, inc, 1, 1);
			} else {
				int l, r, inc;
				cin>>l>>r>>inc;
				update(seg, 0, n-1, l-1, r-1, inc, 2, 1);
			}
		}
	}
	return 0;
}
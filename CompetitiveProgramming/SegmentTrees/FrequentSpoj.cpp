#include<iostream>
#include <stdio.h>
#define ll long long int
using namespace std;
ll arr[100005];
class Custom {
public:
	ll leftmost_el;
	ll leftmost_val;
	ll rightmost_el;
	ll rightmost_val;
	ll ans;
	Custom(ll leftmost_el, ll leftmost_val, ll rightmost_el, ll rightmost_val, ll ans = 1) {
		this->leftmost_el = leftmost_el;
		this->leftmost_val = leftmost_val;
		this->rightmost_el = rightmost_el;
		this->rightmost_val = rightmost_val;
		this->ans = ans;	
	}
};

Custom* merge(Custom* x, Custom *y) {
		Custom* res = new Custom(0,0,0,0,0);
		res->leftmost_el = x->leftmost_el;
		res->leftmost_val = x->leftmost_val;
		res->rightmost_el = y->rightmost_el;
		res->rightmost_val = y->rightmost_val;
		res->ans = max(x->ans, y->ans);
		if(x->leftmost_el == y->leftmost_el) {
			res->leftmost_val+=y->leftmost_val;
		}
		if(x->rightmost_el == y->rightmost_el) {
			res->rightmost_val+=x->rightmost_val;
		}
		if(x->rightmost_el == y->leftmost_el) {
			res->ans = max(res->ans, x->rightmost_val+y->leftmost_val);
		}
		return res;
	}

void buildTree(ll *arr, Custom **seg, ll L, ll R, ll treeIndex) {
	if(L > R) return;
	if(L == R) {
		seg[treeIndex] = new Custom(arr[L], 1, arr[L], 1, 1);
		return;
	}
	ll mid = (L+R)/2;
	buildTree(arr, seg, L, mid, 2*treeIndex+1);
	buildTree(arr, seg, mid + 1, R, 2*treeIndex+2);
	seg[treeIndex] = merge(seg[2*treeIndex+1], seg[2*treeIndex+2]);
}

Custom* query(Custom **seg, ll L, ll R, ll S, ll E, ll treeIndex) {
	if(S > E or S > R or E < L) {
		return new Custom(0,0,0,0,0);
	} 
	if(S >= L and E <= R) {
		return seg[treeIndex];
	}
	ll mid = (S+E)/2;
	Custom* left = query(seg, L, R, S, mid, 2*treeIndex+1);
	Custom* right = query(seg, L, R, mid+1, E, 2*treeIndex+2);
	Custom* ans = merge(left, right);
	return ans;
}

int main(int argc, char const *argv[])
{
	ll n, q;
	scanf("%lld", &n);
	while(n) {
		scanf("%lld", &q);
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		Custom **seg = new Custom*[4*n];
		buildTree(arr, seg, 0, n-1, 0);
		while(q--) {
			ll L, R;
			scanf("%lld%lld", &L, &R);
			Custom *result = query(seg, L-1, R-1, 0, n-1, 0);
			printf("%lld\n",result->ans);
		}
		scanf("%lld", &n);
	}
	return 0;
}
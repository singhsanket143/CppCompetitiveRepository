#include <iostream>
#define ll long long int
using namespace std;


void buildTree(ll *seg, ll *arr, int n, int l, int r, int treeNode) {
	if(l > r) return;
	if(l == r) {
		seg[treeNode] = 0;
		return;
	}
	int mid = (l+r)/2;
	buildTree(seg, arr, n, l, mid, 2*treeNode);
	buildTree(seg, arr, n, mid+1, r, 2*treeNode+1);
	seg[treeNode] = seg[2*treeNode] + seg[2*treeNode+1];
	return;
}

void updateLazy(ll* seg, ll *arr, ll *lazy, int l, int h, int sR, int eR, int treeNode, int n, ll inc) {
	if(l > h) {
		return;
	}
	if(lazy[treeNode] != 0) {
		seg[treeNode] += (h-l+1)*lazy[treeNode];
		if(h!=l) {
			lazy[2*treeNode] += lazy[treeNode];
			lazy[2*treeNode+1] += lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	if(l > eR or h < sR) {
		return;
	}
	if(l >= sR and h <= eR) {
		seg[treeNode] += (h-l+1)*inc;
		if(l!=h) {
			lazy[2*treeNode] += inc;
			lazy[2*treeNode+1] += inc;
		}
		return;
	}
	int mid = (l+h)/2;
	updateLazy(seg, arr, lazy, l, mid, sR, eR, 2*treeNode, n, inc);
	updateLazy(seg, arr, lazy, mid+1, h, sR, eR, 2*treeNode+1, n, inc);
	seg[treeNode] = seg[2*treeNode] + seg[2*treeNode+1];
}

ll queryLazy(ll* seg, ll *lazy, int l, int h, int sR, int eR, int treeNode, int n) {
	if(l > h) {
		return 0;
	}
	if(lazy[treeNode] != 0) {
		seg[treeNode] += (h-l+1)*lazy[treeNode];
		if(h!=l) {
			lazy[2*treeNode] += lazy[treeNode];
			lazy[2*treeNode+1] += lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	if(l > eR or h < sR) {
		return 0;
	}
	if(l >= sR and h <= eR) {
		return seg[treeNode];
		
	}
	int mid = (l+h)/2;
	ll left = queryLazy(seg, lazy, l, mid, sR, eR, 2*treeNode, n);
	ll right = queryLazy(seg, lazy, mid+1, h, sR, eR, 2*treeNode+1, n);
	return left+right;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, c;
		cin>>n>>c;
		ll *arr = new ll[n]();
		ll *seg = new ll[4*n]();
		ll *lazy = new ll[4*n]();
		buildTree(seg, arr, n, 0, n-1, 1);
		while(c--) {
			int type;
			cin>>type;
			if(type == 0) {
				int l, r, inc;
				cin>>l>>r>>inc;
				updateLazy(seg, arr, lazy, 0, n-1, l-1, r-1, 1, n, inc);
			} else {
				int l, r;
				cin>>l>>r;
				cout<<queryLazy(seg, lazy, 0, n-1, l-1, r-1, 1, n)<<endl;
			}
		}	
	}
	return 0;
}
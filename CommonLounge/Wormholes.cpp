#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x, y;
	cin>>n>>x>>y;
	pair<int, int > arr[n];
	for(int i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		arr[i] = make_pair(a, b);
	}
	int W[x];
	int V[y];
	for(int i=0;i<x;i++) {
		cin>>W[i];
	}
	for(int i=0;i<y;i++) {
		cin>>V[i];
	}
	std::vector<int> v(V, V+y), w(W, W+x);
	std::vector<int>::iterator low, hi;
	sort(arr, arr+n);
	sort(w.begin(), w.end());
	sort(v.begin(), v.end());
	
	int i=0, j=0, k=0;
	long long int ans=INT_MAX, candidate=0;
	while(i<n) {
		int m1, m2;
		int t1 = arr[i].first;
		low = upper_bound(w.begin(), w.end(), t1);
		m1 = (low-w.begin()-1);
		if(m1<0) {
			i++;
			continue;
		}
		int t2 = arr[i].second;
		hi = lower_bound(v.begin(), v.end(), t2);
		m2 = (hi-v.begin());
		if(m2>=v.size()) {
			i++;
			continue;
		}
		candidate = v[m2] - w[m1] + 1;
		ans = (ans>candidate)?candidate:ans;
		// cout<<v[m2]<<" "<<w[m1]<<" "<<ans<<" "<<t1<<" "<<t2<<" "<<i<<" "<<m1<<" "<<m2<<"\n";
		i++;
	}
	cout<<ans;
	return 0;
}

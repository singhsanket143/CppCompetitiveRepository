#include <bits/stdc++.h>
#define lli long long int
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	lli k;
	cin>>k;
	ll *a = new ll[n];
	ll *b = new ll[n];
	lli total_ballons = 0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		total_ballons+=a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	if(total_ballons <= k) {
		cout<<"0";
		return 0;
	}
	priority_queue< pair<lli, pair<ll, ll> > > qu;
	pair<lli, pair<ll, ll> > arr[n];
	for(int i=0;i<n;i++) {
		arr[i] = make_pair(a[i]*b[i], make_pair(a[i], b[i]));
	}
	sort(arr, arr+n);
	lli lo = arr[0].first, hi = arr[n-1].first;
	lli global_min = arr[n-1].first;
	while(lo<=hi) {
		lli mid = (lo+hi)/2;
		lli temp = k;
		lli local_mixima = INT_MIN;
		int status = n-1;
		for(int i = n-1;i>=0;i--) {
			lli a = arr[i].first;
			lli b = arr[i].second.first;
			lli c = arr[i].second.second;
			
			lli factor = (mid)/c;
			if(mid%c==0) {
				factor-=1;
			}
			lli num = c*factor;
			lli sub=0, val=0;
			if(num<a and temp>=0) {
				sub = a - num;
				val = sub/c;
				if(val>temp and temp>0){
					// cout<<val<<",,"<<temp<<",,"<<endl;
					// lli p=val/temp;
					// lli q = p*temp;
					// lli rem = val-q;
					// val=val - rem;
					val = temp;

				}
				if(temp-val>=0){
					temp -= val;
					b -= val;
				} 
			}
			
			local_mixima = max(local_mixima, b*c);
			// cout<<local_mixima<<","<<temp<<","<<mid<<","<<lo<<","<<hi<<","<<sub<<","<<val<<","<<factor<<","<<num<<endl;
			// if(temp<=0) {
			// 	break;
			// }
		}

		global_min = min(global_min, local_mixima);
		// cout<<global_min<<" "<<local_mixima<<endl;
		if(temp<=0) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
		// cout<<"lo="<<lo<<" hi= "<<hi<<endl;
	}
	cout<<global_min;
	return 0;
}
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
std::map<ll, ll> mp;
ll min_global;
ll mincount_global;

void setfunc(ll min_global, ll num2, ll t, ll count) {
	if(min_global > num2) {
			min_global = num2;
			mincount_global = count+t;
		} else if (min_global == num2) {
			mincount_global = (mincount_global > count+t)?(count+t):mincount_global;
	}
}
ll digitsum(ll num) {
	ll result = 0;
	while(num > 0) {
		result += num%10;
		num /= 10;
	}
	return result;
}

void mindigit(ll num, ll count, ll d, int level) {
	if(level>=21) {
		return;
	}
	ll num2 = digitsum(num);
	std::map<ll,ll>::iterator it;
	it = mp.find(num2);
	if(it == mp.end()) {
		int t = (num>9)?1:0;
		mp.insert(pair<ll, ll>(num2, count+t));
		// mp.insert(pair<ll, ll>(num+d, count+1));
		setfunc( min_global,  num2,  t, count);
		if(min_global > num2) {
			min_global = num2;
			mincount_global = count+t;
		} else if (min_global == num2) {
			mincount_global = (mincount_global > count+t)?(count+t):mincount_global;
		}
		mindigit(num+d, count+1, d, level+1);
		mindigit(num2, count+t, d, level+1);
		mp.erase(num2);
	} 
	else {
		setfunc( min_global,  num2,  0, count);
		// int t = (num>9)?1:0;
		// if(it->second > count+t) {
		// 	mp.insert(pair<ll, ll>(num2, count+t));
		// }
		// mindigit(num+d, count+1, d, level+1);
		// mindigit(num2, count+t, d, level+1);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll n, d;
		cin>>n>>d;
		mp.clear();
		min_global = INT_MAX;
		mincount_global = INT_MAX;
		mindigit(n,0, d, 0);
		map <ll, ll> :: iterator itr; 
		ll min_value1 = INT_MAX, min_value2 = INT_MAX;
		for (itr = mp.begin(); itr != mp.end(); ++itr) 
    	{ 
        	if(itr->first < min_value1) {
        		min_value1 = itr->first;
        		min_value2 = itr->second;
        	}
    	// cout<<itr->first<<" "<<itr->second<<endl;

    	} 

    	cout<<min_global<<" "<<mincount_global<<endl;
	}
	return 0;
}
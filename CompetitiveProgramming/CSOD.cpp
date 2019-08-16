#include <iostream>
#include <string>
#include <cfloat>
#include <limits>
#include "map"
using namespace std;
map<string, bool> mp;

class item {
public:
	string str;
	double count;
	double discount;
};

bool cmp(item x, item y) {
	if(x.discount == y.discount) {
		return strcmp(x.str.c_str(), y.str.c_str());
	} else {
		return x.discount > y.discount;
	}
}

int compare(string s1, string s2) {
	if(s1.length()!=s2.length()) return -1;
	for(int i=0;i<s1.length();i++) {
		if(s1[i]!=s2[i]) return -1;
	}
	return 0;
}

void disc(item *arr, int n, item x, item &y) {
	// cout<<x.str<<endl;
	if(mp.find(x.str)==mp.end()) {
		int cp1 = x.count*x.discount;
		y.discount = 0;
		y.count = cp1;
		return ;
	}
	double best = 999999999.9;
	double best_d = 0;
	bool change = false;
	for(int i=0;i<n;i++) {
		if(compare(arr[i].str, x.str)==0) {
			if(arr[i].count > x.count) continue;
			else {
				int cp = x.count*x.discount;
				double np = (cp*arr[i].discount)/100;
				cp = cp-np;
				if(cp<best) {best = cp;best_d = arr[i].discount;change = true;}
			}
		}
	}
	if(change==true) {
		y.discount = best_d;
		y.count = best;
	} else {
		y.discount = 0;
		y.count = x.count*x.discount;
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	item arr[n];

	for(int i=0;i<n;i++) {
		cin>>arr[i].str;
		cin>>arr[i].count;
		cin>>arr[i].discount;
		mp[arr[i].str] = true;
	}
	int m;
	cin>>m;
	item cart[m];
	for(int i=0;i<m;i++) {
		cin>>cart[i].str;
		cin>>cart[i].count;
		cin>>cart[i].discount;
	}
	item result[m];
	for(int i=0;i<m;i++) {
		result[i].str = cart[i].str;
		disc(arr, n, cart[i], result[i]);
	}
		double total = 0;
		sort(result, result+m, cmp);
	for(int i=0;i<m;i++) {
		total+=result[i].count;
		printf("%s %0.2f\n", result[i].str.c_str(), result[i].count);
	}
	printf("Total %0.2f", total);
	return 0;
}

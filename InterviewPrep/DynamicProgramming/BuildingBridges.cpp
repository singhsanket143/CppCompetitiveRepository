#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class city {
public:
	int north;
	int south;
	city(int north, int south) {
		this->north = north;
		this->south = south;
	}
};

bool cmp(city *x, city *y) {
	if(x->south == y->south) {
		return x->north < y->north;
	}
	return x->south < y->south;
}

int BuildingBridges(city **values, int n) {
	sort(values, values+n, cmp);
	vector<int> dp(n);
	fill(dp.begin(), dp.end(), 1);
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(values[j]->north <= values[i]->north and dp[i] < 1+dp[j]) {
				dp[i] = 1+dp[j];
			}
		}
	}

	int max_val = dp[0];
	for(int i=1;i<n;i++) {
		if(max_val < dp[i]) max_val = dp[i];
	}
	return max_val;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	city **value = new city*[n];
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		value[i] = new city(a, b);
	}
	cout<<BuildingBridges(value, n);
	return 0;
}

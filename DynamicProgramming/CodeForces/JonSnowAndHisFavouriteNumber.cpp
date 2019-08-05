#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, x;
	cin>>n>>k>>x;
	int *freq = new int[1500]();
	for(int i=0;i<n;i++) {
		int f;
		cin>>f;
		freq[f]++;
	}
	int *temp = new int[1500];
	while(k--) {
		for(int i=0;i<1500;i++) {
			temp[i] = freq[i];
		}
		int parity = 0;
		for(int i=0;i<1500;i++) {
			if(freq[i] > 0) {
				int curr = i^x;
				int change_val = freq[i]/2;
				if(parity == 0) {
					change_val += (freq[i]&1);
				}
				temp[i] -= change_val;
				temp[curr] += change_val;
				parity ^= (freq[i]&1);
			}
		}
		for(int i=0;i<1500;i++) {
			freq[i] = temp[i];
		}
	}
	int min_val = INT_MAX, max_val = INT_MIN;;
	for(int i=0;i<1500;i++) {
		if(freq[i]>0) {
			min_val = min(min_val, i);
			max_val = max(max_val, i);
		}
	}
	cout<<max_val<<" "<<min_val;
	return 0;
}

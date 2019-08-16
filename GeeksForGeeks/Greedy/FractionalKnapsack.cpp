#include <iostream>
#include <algorithm>
using namespace std;

class item {
public:
	int value;
	int weight;
};

bool cmp(item a, item b) {
	double x = double((double)a.value/(double)a.weight);
	double y = double((double)b.value/(double)b.weight);
	return x > y;
}

int main() {
	int n, W;
	cin>>n>>W;
	item arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i].value;
		cin>>arr[i].weight;
	}
	sort(arr, arr+n, cmp);
	int currWeight = 0;
	double finalValue = 0.0;
	for(int i=0;i<n;i++) {
		if(arr[i].weight+currWeight <= W) {
			finalValue += arr[i].value;
			currWeight += arr[i].weight;
		} else {
			int remain = W-currWeight;
			finalValue += arr[i].value * ((double)remain/arr[i].weight);
			break;
		}
	}
	printf("%0.1lf", finalValue);
}

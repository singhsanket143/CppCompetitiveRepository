#include<iostream>
using namespace std;
int main() {
	
	int dates[200];

	int arr[] = {1,2,3,4,5,6,78,89};

	int zeros[10] = {0}; // to initialize whole array with zeroes

	int ones[6] = {1, 2};

	cout<<arr[0]<<" "<<dates[1]<<endl;
	cout<<zeros[0]<<" "<<zeros[1]<<" "<<zeros[5]<<endl;
	cout<<ones[0]<<" "<<ones[1]<<" "<<ones[4]<<endl;

	int n;
	cin>>n;

	int a[n];
	cout<<sizeof(a)<<endl;

	int i = 0;
	while(i < 10) {
		cout<<zeros[i]<<" "<<endl;
		i = i + 1;
	}
	return 0;
}
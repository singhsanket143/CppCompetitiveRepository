#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		arr[i] = 0;
	}
	int q;
	cin>>q;
	while(q--){
		int start, end, c;
		cin>>start>>end>>c;
		arr[start] += c;
		if(end+1 >= n) {
			// nothing
		} else {
			arr[end+1]-=c;
		}
	}
	for(int i=1;i<n;i++) { // Cumulative sum
		arr[i] = arr[i] + arr[i-1];
	}
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<", ";
	}
	return 0;
}

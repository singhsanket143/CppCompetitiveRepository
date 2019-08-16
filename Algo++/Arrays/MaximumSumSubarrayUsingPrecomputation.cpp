#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		int temp[n];
		temp[0] = arr[0];
		for(int i=1;i<n;i++) {
			temp[i] = arr[i]+temp[i-1];
		}
		int maxSum=0;
		for(int i=1;i<n;i++){
			for(int j=i;j<n;j++) {
				int candidate = temp[j]-temp[i-1];
				maxSum = (candidate>maxSum)?candidate:maxSum;
			}
		}
		for(int i=0;i<n;i++) {
			maxSum = (temp[i]>maxSum)?temp[i]:maxSum;
		}
		cout<<maxSum<<endl;
	}
	return 0;
}

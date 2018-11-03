#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		long long int sum=0;
		cin>>n;

		int arr[n];
		for(int i=0;i<=n;i++) {
			arr[i] = 0;
		}
		int max = 0;
		for(int i=0;i<n;i++) {
			string str;
			int x;
			cin>>str;
			cin>>x;
			arr[x]++;
		}
		// for(int i=0;i<=n;i++) {
		// 	cout<<arr[i]<<" ";
		// }
		cout<<endl;
		int pos = 1;
		for(int i=1;i<=n;i++) {
			while(arr[i]) {
				sum+=abs(pos-i);
				pos++;
				arr[i]--;
				// cout<<sum<<","<<abs(pos-i)<<","<<pos<<","<<i<<endl;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

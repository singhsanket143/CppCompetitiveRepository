#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long long int arr[3] = {0};
		arr[0]=1;
		if(n==0) {
			cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
			continue;
		}
		int count=0, i=0;
		while(i<n) {
		while(count<2 and i<n) {
			count++;
			i++;
		}
		
		if(i==n) {
			// cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<" if1 "<<count<<" "<<i<<" "<<"\n";
			cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
			continue;
		}
		arr[1]=arr[0];
		arr[0]=0;
		count=0;
		
		while(count<8 and i<n) {
			count++;
			i++;
		}
		
		if(i==n) {
			// cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<" if2 "<<count<<" "<<i<<" "<<"\n";
			cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
			continue;
		}
		arr[2]=arr[1];
		arr[1]=0;
		count=0;
		
		while(count<16 and i<n) {
			count++;
			i++;
		}
		
		if(i==n) {
			// cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<" if3 "<<count<<" "<<i<<" "<<"\n";
			cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
			continue;
		}
		arr[0]=2*arr[2];
		arr[2]=0;
		count=0;
		}
	}
	return 0;
}

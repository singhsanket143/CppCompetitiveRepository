#include <iostream>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}

		if(n%2!=0) {

			cout<<"NO"<<endl;
			continue;
		} 
		int k=n/2;
		bool status = false;
		for(int i=0;i<n-k;i++) {
			if((arr[i]!=-1 and arr[i+k]!=-1) and (arr[i] != arr[i+k])) {
				cout<<"NO"<<endl;
				status =true;
				break;
			}
			if((arr[i]!=-1 and arr[i+k]!=-1) and (arr[i] == arr[i+k])) {
				continue;
			} else if(arr[i]==-1 or arr[i+k]==-1){
				int m = max(arr[i], arr[i+k]);
				if(m!=-1) {
					arr[i]=m;
					arr[i+k]=m;
				} else {
					arr[i]=1;
					arr[i+k]=1;
				}
				
			}
		}
		if(status==false) {
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
 
	}
	return 0;
}
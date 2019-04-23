#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		int k;
		cin>>k;
		bool status = false;
		for(int i=0;i<n;i++) {
			if(arr[i]==k) {
				cout<<i<<endl;
				status=true;
				break;
			}
		}
		if(status==false)
		cout<<-1<<endl;
	}
	return 0;
}
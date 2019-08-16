#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    int s=0, m=0, e=n-1;
	    while(m<=e) {
	        if(arr[m]==1) {
	            m++;
	        } else if(arr[m]==2){
	            swap(arr[e], arr[m]);
	            e--;
	        } else {
	            swap(arr[s], arr[m]);
	            m++;
	            s++;
	        }
	    }
	    for(int i=0;i<n;i++) {
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
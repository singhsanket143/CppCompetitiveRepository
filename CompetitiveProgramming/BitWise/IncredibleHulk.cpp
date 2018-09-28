#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
	    cin>>n;
	    int ans=0;
	    for(;n>0;n>>=1) {
	        ans = ans + (n&1);
	    }
	    cout<<ans;
	}
    
    return 0;
}

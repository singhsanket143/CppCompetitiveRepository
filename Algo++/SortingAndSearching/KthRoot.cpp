#include "iostream"
using namespace std;
#define ll long long int

int main(int argc, char* argv[])
{
    int t;
    cin>>t;
    while(t--) {
        ll n, k;
        cin>>n>>k;
        if(k==1){
            cout<<n<<endl;
            continue;
        }
        ll lo = 1, hi = 1000000, ans = -1;
        while(lo<=hi) {
            ll mid = (lo+hi)/2;
            ll var=1;
			for(int i=1;i<=k;i++)
			{
				var*=mid;
				if(var>n)
				{
					break;
				}
			}
            if(var == n) {
                ans = mid;
                break;
            } else if (var < n) {
                ans = mid;
                lo=mid+1;
            } else {
                hi=mid-1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

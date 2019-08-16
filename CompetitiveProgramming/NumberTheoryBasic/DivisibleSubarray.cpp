#include "iostream"
#include "cstring"
#define  ll long long int
using namespace std;
ll arr[100010];
ll temp[100010];
int main(int argc, char* argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        ll sum = 0;
        memset(temp,0,sizeof temp);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
            sum%=n;
            sum=(sum+n)%n;
            temp[sum]++;
        }
        ll ans+=(temp[0]*(temp[0]+1))/2;
        for(int i=1;i<n;i++) {
            ans+=(temp[i]*(temp[i]-1))/2;
        }

        cout<<ans<<endl;
    }

    return 0;
}

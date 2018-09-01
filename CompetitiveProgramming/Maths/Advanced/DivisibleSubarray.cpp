#include "iostream"
#include "cstring"
using namespace std;
#define ll long long int
ll arr[100005], prefixSum[100005];
int main(int argc, char* argv[])
{

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll sum = 0;
        memset(prefixSum, 0, sizeof prefixSum);
        prefixSum[0]=1;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
            sum%=n;
            sum = (sum+n)%n;
            prefixSum[sum]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            ll no=prefixSum[i];
            ans += ((no)*(no-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

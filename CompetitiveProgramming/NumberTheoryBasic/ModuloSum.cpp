#include "iostream"
#include "cstring"
#define ll long long int
using namespace std;
ll arr[1000005];
ll dp[][];
int main(int argc, char* argv[])
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll sum = 0;
    memset(temp, 0, sizeof temp);
    for(int i = 1;i<n;i++) {
        arr[i]+=arr[i-1];
    }
    temp[0]=1;
    for(int i = 1;i<n;i++) {
        temp[arr[i]%m]++;
    }
    for(int i=0;i<n;i++) {
        if(temp[i]>1){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

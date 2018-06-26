#include "iostream"
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int result[n];
    for(int i=0;i<n;i++) {
        result[i]=1;
    }

    for(int i=0;i<n;i++){
        if(arr[i]>=107) {
            result[i]=0;
            continue;
        }
        for(int j=1;j<=arr[i];j++) {
            result[i] = ((result[i]%107)*(j%107))%107;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans=((ans%107)+(result[i]%107))%107;
    }
    cout<<ans<<endl;

    return 0;
}

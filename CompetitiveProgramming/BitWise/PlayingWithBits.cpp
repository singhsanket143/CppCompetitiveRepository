#include "iostream"
using namespace std;
int countSetBits(int n) {
    int count = 0;
    while(n) {
        n = n & (n-1);
        count++;
    }
    return count;
}
int main(int argc, char* argv[])
{
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i=a;i<=b;i++) {
            ans+=countSetBits(i);
        }
        cout<<ans<<endl;
    }

    return 0;
}

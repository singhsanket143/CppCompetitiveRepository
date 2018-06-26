#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int ans=0;
    for(;n>0;n>>=1) {
        ans = ans + (n&1);
    }
    cout<<ans;
    return 0;
}

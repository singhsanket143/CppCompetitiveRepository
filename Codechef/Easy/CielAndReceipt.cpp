#include<iostream>
using namespace std;
long largest_power(long N)
{
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);
    return (N+1)>>1;
}
int main() {
std::ios::sync_with_stdio(false);
int t;
cin>>t;
while(t--) {
    int n;
    cin>>n;
    int count=0;
    while(n>1) {
        if(largest_power(n)<=2048)
            n = n-largest_power(n);
        else
            n=n-2048;
        count++;
    }
    if(n==1) {
        count++;
    }
    cout<<count<<endl;
}
return 0;
}

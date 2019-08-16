#include "iostream"
#include "math.h"
#define ll long long int
using namespace std;

ll largest_prime(ll n) {
    int temp = n;
    while(n%2==0) {
        n=n/2;
    }
    if(n==1) {
        return 2;
    }
    int i;
    for(i=3;i<=sqrt(n);i+=2) {
        while(n%i==0) {
            n=n/i;
        }
    }
    if(n>2) {
        return n;
    } else {
        return i-2;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        cout<<largest_prime(n)<<endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define pb push_back
typedef long long int ll;

vector<int>* sieve() {
    bool *isPrime = new bool[1000008];
    std::vector<int>* primes = new vector<int>();
    for(int i=2;i<=1000000;i++) {
        isPrime[i] = true;
    }
    for(int i=2;i*i<=1000000; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=1000000; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    primes->pb(2);
    for(int i=3;i<=1000000;i+=2) {
        if(isPrime[i]) {
            primes->pb(i);
        }
    }
    return primes;
}

int main(int argc, char const *argv[])
{
    vector<int> *v = sieve();
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<v->at(n-1)<<endl;
    }
    return 0;
}
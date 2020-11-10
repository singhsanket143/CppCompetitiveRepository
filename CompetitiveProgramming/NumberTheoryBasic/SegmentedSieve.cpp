#include "bits/stdc++.h"
using namespace std;
#define MAX 100005
vector<bool>isPrime (MAX,true);
unsigned primearray[100005];


void gen_primes(){
    isPrime[0]=isPrime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(unsigned j=2*i;j<=MAX;j+=i) isPrime[j]=false;
        }
    }
    unsigned idx = 1;
    primearray[0]=2;
    
    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            primearray[idx++]=i;
        }     
    }
}

void segmentedSieve(long long a, long long b) {

    bool segSieve[b-a+1];
    if(a==1)a++;
    memset(segSieve, 1, sizeof(segSieve));
    for(int i = 0; primearray[i]*primearray[i]<=b;i++) {
        unsigned p = primearray[i];
        long long int j = (a/p)*p;
        if(j < a) j+=p;
        for(;j<=b;j+=p) {
            if(j!=p) {
                segSieve[j-a] = 0;
            }
        }
    }

    for(long long int i = a; i<=b; i++) {
        if(i<=1) continue;
        if(segSieve[i-a]==1 or i==2) printf("%lld\n", i);
    }
}

int main(int argc, char* argv[])
{

    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int a, b, t;
    gen_primes();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        segmentedSieve(a, b);
        // cout<<eandl;
    }
    return 0;
}

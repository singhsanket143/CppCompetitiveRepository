#include "iostream"
using namespace std;

void sieveGenerate(int n, int sieve[]) {
    sieve[0] = sieve[1] = 0;
    sieve[2] = 1;
    for(int i=3;i<n;i+=2) {
        sieve[i] = 1;
    }
    for(int i = 3; i <= n; i++) {
        if(sieve[i]) {
            for(int j = i*i; j <= n; j+=2*i) {
                sieve[i] = 0;
            }
        }
    }
    return;
}

void segmentedSieve(int sieve[],int n, long long a, long long b) {

    bool segSieve[b-a+1];
    memset(segSieve, 1, sizeof(segSieve));

    for(long long i = 2; i*i<=b;i++) {
        for(long long j=a;j<=b;j++) {
            if(sieve[i]) {
                if(j==1) continue;
                if(j%i==0) segSieve[j-a] = 0;
            }
        }
    }

    for(long long i = a; i<=b; i++) {
        if(segSieve[i-a]==1 or i==2) cout<<i<<endl;
    }
}

int main(int argc, char* argv[])
{

    int a, b, t;
    cin>>t;
    int sieve[100001];
    sieveGenerate(100001, sieve);
    while(t-->0){
        cin>>a>>b;
        segmentedSieve(sieve, 100001, a, b);
    }
    return 0;
}

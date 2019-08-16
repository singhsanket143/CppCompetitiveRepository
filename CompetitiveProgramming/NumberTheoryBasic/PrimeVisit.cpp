#include "iostream"
using namespace std;


void primeSieve(int n, int sieve[]) {
    sieve[0] = sieve[1] = 0;
    sieve[2] = 1; 

    for(int i = 3; i<=n; i+=2) {
        sieve[i] = 1;
    }
    for(int i = 3; i<=n; i++) {
        if(sieve[i]) {
            for(int j = i*i; j <= n; j += 2*i) {
                sieve[j] = 0;
            }
        }
    }
    return ;
}

int main()
{
    int N = 1000;
    int* sieve = new int[1000];
    for(int i = 0;i<N;i++) {
        sieve[i] = 0;
    }
    primeSieve(1000, sieve);
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        int count = 0;
        for(int i=a;i<=b;i++) {
            if(sieve[i]) {
                count++;
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}

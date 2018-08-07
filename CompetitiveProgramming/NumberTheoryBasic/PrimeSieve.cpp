#include "iostream"
using namespace std;
int sieve[100000];
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

int main(int argc, char* argv[])
{


    primeSieve(100000, sieve);
    for(int i = 0; i <= 25; i++) {
        cout<<sieve[i]<<" ";
    }
    return 0;
}

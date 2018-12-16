#include "iostream"
#include <vector>
using namespace std;
int sieve[100000];
#define MAX 10000000
vector<bool>isPrime (MAX,true);
unsigned primearray[5761459];


void gen_primes(){
    isPrime[0]=isPrime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(unsigned j=i;j*i<=MAX;j++) isPrime[i*j]=false;
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

void primeSieve2(int n, int sieve[]) {
        sieve[0] = sieve[1] = 0;
        sieve[2] = 1;
        for(int i=3;i<=n;i+=2) {
            sieve[i] = 1;
        }
        for (int div = 2; div * div < n; div++) {
            if (sieve[div] == 1) {
                for (int multiple = 2; div * multiple <= n; multiple++) {
                    sieve[div * multiple] = 0;
                }
            }
        }
    }

int main(int argc, char* argv[])
{


    primeSieve(100000, sieve);
    for(int i = 0; i <= 25; i++) {
        cout<<sieve[i]<<" ";
    }
    return 0;
}

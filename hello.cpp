#include <bits/stdc++.h>
using namespace std;
vector<bool> p(100000,false);
void prime_sieve(vector<bool> p, long long int n){
    p[0]=p[1] = 0;
    p[2] = 1;
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }
    for(int i=3; i<=n; i+=2){
        if(p[i]){
            for(int j=i*i; j<=n; j+=2*i){
                p[j] = 0;
            }
        }
    }

}
int main() {
    int N = 100000;
    // int p[N] = {0};
    prime_sieve(p,100000);
    int t;
    cin>>t;
    int primes_req;
    for(int i=1; i<=t; i++){
        cin>>primes_req;
        int primes_found=0;
        for(long long int j=0; j<=100000; j++){
            if(p[j]){
                primes_found++;
            }
            if(primes_found==primes_req){
                cout<<j<<endl;
                break;
            }
        }       
    }

}

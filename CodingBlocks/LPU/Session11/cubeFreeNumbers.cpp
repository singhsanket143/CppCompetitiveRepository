#include <iostream>
#include <math.h>
#define max 100005
using namespace std;

bool sieve[max] = {};
vector<int> primes;
int main()
{
    sieve[0] = true;
    sieve[1] = true;
    for (int i = 2; i <= sqrt(max); i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j * i < max; j++)
            {
                sieve[j * i] = true;
            }
        }
    }
    for(int i = 2; i < max; i++) {
        if(!sieve[i]) {
            primes.push_back(i);
        }
    }
    memset(sieve,0,)
    for(int i = 0; i < primes.size(); i++) {
        int cube=primes[i]*primes[i]*primes[i];
        for(int i=1;i)
    }
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        int sqrt_n = sqrt(n);
        cout << sieve_count[sqrt_n] << endl;
    }
}
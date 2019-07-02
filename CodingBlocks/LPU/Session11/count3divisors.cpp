#include <iostream>
#include <math.h>
#define max 100005
using namespace std;

bool sieve[max] = {};
int sieve_count[max] = {};
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
    for(int i=2;i<max;i++) {
        if(!sieve[i]) {
            sieve_count[i] = sieve_count[i-1] + 1;
        } else {
            sieve_count[i] = sieve_count[i-1];
        }
    }
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        int sqrt_n = sqrt(n);
        cout << sieve_count[sqrt_n] << endl;
    }
}
#include <iostream>
#include <math.h>
#define max 100005
using namespace std;

bool sieve[max] = {};
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
    for (int i = 0; i < max; i++)
    {
        if (!sieve[i])
            cout << i << " ";
    }
    cout << endl;
}